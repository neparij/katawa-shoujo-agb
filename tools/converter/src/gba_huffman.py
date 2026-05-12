import heapq
from dataclasses import dataclass
from typing import Dict, List, Optional, Tuple


@dataclass
class _Node:
    count: int
    val: int
    left: Optional["_Node"] = None
    right: Optional["_Node"] = None
    parent: Optional["_Node"] = None

    code: int = 0
    code_len: int = 0
    leaves: int = 0

    def is_parent(self) -> bool:
        return self.left is not None and self.right is not None

    def num_nodes(self) -> int:
        if self.is_parent():
            assert self.left and self.right
            return self.left.num_nodes() + self.right.num_nodes() + 1
        return 1

    def num_leaves(self) -> int:
        if self.leaves:
            return self.leaves
        if self.is_parent():
            assert self.left and self.right
            self.leaves = self.left.num_leaves() + self.right.num_leaves()
        else:
            self.leaves = 1
        return self.leaves


def _build_tree(hist: List[int]) -> _Node:
    """
    Closely mirrors grit/libgrit/cprs_huff.cpp buildTree() for 8-bit mode.
    """
    heap: list[Tuple[int, int, int, _Node]] = []
    uid = 0
    for v, c in enumerate(hist):
        if c <= 0:
            continue
        heapq.heappush(heap, (c, v, uid, _Node(count=c, val=v)))
        uid += 1

    if not heap:
        root = _Node(count=1, val=0)
        return _Node(count=1, val=0, left=root, right=_Node(count=0, val=0))

    while len(heap) > 1:
        c0, v0, _, n0 = heapq.heappop(heap)
        c1, v1, _, n1 = heapq.heappop(heap)
        # Important: like grit, internal node 'val' starts at 0.
        # It will be overwritten during serialize/fixup with offset values.
        parent = _Node(count=c0 + c1, val=0, left=n0, right=n1)
        n0.parent = parent
        n1.parent = parent
        heapq.heappush(heap, (parent.count, parent.val, uid, parent))
        uid += 1

    root = heap[0][-1]
    if not root.is_parent():
        root = _Node(count=root.count, val=0, left=root, right=_Node(count=0, val=0))
        root.left.parent = root
        root.right.parent = root
    return root


def _build_codes(node: _Node, code: int, code_len: int) -> None:
    if code_len >= 32:
        raise ValueError("Huffman code length exceeded 31 bits")
    if node.is_parent():
        assert node.left and node.right
        _build_codes(node.left, (code << 1) | 0, code_len + 1)
        _build_codes(node.right, (code << 1) | 1, code_len + 1)
    else:
        node.code = code
        node.code_len = max(1, code_len)


def _build_lookup(lookup: List[Optional[_Node]], node: _Node) -> None:
    if not node.is_parent():
        lookup[node.val] = node
        return
    assert node.left and node.right
    _build_lookup(lookup, node.left)
    _build_lookup(lookup, node.right)


def _serialize_tree(tree: List[Optional[_Node]], node: _Node, nxt: int) -> None:
    """
    Port of grit Node::serializeTree.
    'tree' is a 1-based array of nodes (tree[1] is root). Slots are Node pointers.
    """
    assert node.is_parent()
    assert node.left and node.right

    if node.num_leaves() > 0x40:
        tree[nxt + 0] = node.left
        tree[nxt + 1] = node.right

        a, b = 0, 1
        if node.right.num_leaves() < node.left.num_leaves():
            a, b = 1, 0

        child_a = node.right if a == 1 else node.left
        child_b = node.right if b == 1 else node.left

        if child_a.is_parent():
            child_a.val = 0
            _serialize_tree(tree, child_a, nxt + 2)

        if child_b.is_parent():
            child_b.val = child_a.num_leaves() - 1
            _serialize_tree(tree, child_b, nxt + 2 * child_a.num_leaves())
        return

    queue: List[_Node] = [node.left, node.right]
    qi = 0
    while qi < len(queue):
        cur = queue[qi]
        qi += 1
        tree[nxt] = cur
        nxt += 1

        if not cur.is_parent():
            continue

        assert cur.left and cur.right
        cur.val = (len(queue) - qi) // 2
        queue.append(cur.left)
        queue.append(cur.right)


def _fixup_tree(tree: List[Optional[_Node]]) -> None:
    """
    Port of grit Node::fixupTree, operating on the Node-pointer array.
    tree indices are 0..len-1, with meaningful nodes at 1..N.
    """
    i = 1
    while i < len(tree):
        n = tree[i]
        if n is None or (not n.is_parent()) or n.val <= 0x3F:
            i += 1
            continue

        shift = n.val - 0x3F

        if (i & 1) and (tree[i - 1] is not None) and (tree[i - 1].val == 0x3F):
            i -= 1
            n = tree[i]
            assert n is not None
            shift = 1

        node_end = i // 2 + 1 + n.val
        node_begin = node_end - shift

        shift_begin = 2 * node_begin
        shift_end = 2 * node_end

        # move last child pair to front
        tmp0, tmp1 = tree[shift_end], tree[shift_end + 1]
        block = tree[shift_begin:shift_end]
        tree[shift_begin + 2 : shift_end + 2] = block
        tree[shift_begin], tree[shift_begin + 1] = tmp0, tmp1

        # adjust offsets
        n.val -= shift
        for index in range(i + 1, shift_begin):
            m = tree[index]
            if m is None or (not m.is_parent()):
                continue
            node_pos = index // 2 + 1 + m.val
            if node_begin <= node_pos < node_end:
                m.val += 1

        m0 = tree[shift_begin + 0]
        m1 = tree[shift_begin + 1]
        if m0 is not None and m0.is_parent():
            m0.val += shift
        if m1 is not None and m1.is_parent():
            m1.val += shift

        for index in range(shift_begin + 2, shift_end + 2):
            m = tree[index]
            if m is None or (not m.is_parent()):
                continue
            node_pos = index // 2 + 1 + m.val
            if node_pos > node_end:
                m.val -= 1

        i += 1


def _encode_tree(root: _Node, node_count: int) -> bytes:
    """
    Build the BIOS tree block exactly like grit does (but for BIOS we can keep it minimal).
    We intentionally emit a fixed 512-byte block with size marker 0xFF (grit style),
    which BIOS accepts: tree_size = (0xFF+1)*2 = 512 bytes.
    """
    # Build node-pointer table exactly like grit:
    # size = (node_count + 2) & ~1
    # (the +2 accounts for the size byte at index 0 and root at index 1)
    minimal_size = (node_count + 2) & ~1
    node_tree: List[Optional[_Node]] = [None] * minimal_size
    node_tree[1] = root
    _serialize_tree(node_tree, root, 2)
    _fixup_tree(node_tree)

    # Encode minimal tree bytes into fixed 512-byte block:
    tree = bytearray(512)
    tree[0] = 0xFF

    for i in range(1, minimal_size):
        n = node_tree[i]
        if n is None:
            tree[i] = 0
            continue
        b = n.val & 0xFF
        if n.is_parent():
            # internal: set leaf flags based on child parent-ness
            assert n.left and n.right
            b = n.val & 0x3F
            if not n.left.is_parent():
                b |= 0x80
            if not n.right.is_parent():
                b |= 0x40
        tree[i] = b

    return bytes(tree)


class _Bitstream:
    def __init__(self, out: bytearray):
        self.out = out
        self.pos = 32
        self.code = 0

    def flush(self) -> None:
        if self.pos >= 32:
            return
        self.out.extend(int(self.code).to_bytes(4, byteorder="little"))
        self.pos = 32
        self.code = 0

    def push(self, code: int, length: int) -> None:
        for i in range(1, length + 1):
            self.pos -= 1
            if code & (1 << (length - i)):
                self.code |= (1 << self.pos)
            else:
                self.code &= ~(1 << self.pos)
            if self.pos == 0:
                self.flush()


def gba_huff_compress_8bit(data: bytes) -> bytes:
    """
    GBA BIOS HuffUnComp compatible Huffman compression (8-bit units).
    Emits:
      - header (0x28 + 24-bit decompressed size)
      - 512-byte tree block with tree[0]=0xFF (grit-style)
      - bitstream (32-bit words, bit31 first), padded to 4 bytes
    """
    if len(data) >= (1 << 24):
        raise ValueError("Data too large for GBA Huffman header (24-bit size)")

    hist = [0] * 256
    for b in data:
        hist[b] += 1

    root = _build_tree(hist)
    _build_codes(root, 0, 0)

    lookup: List[Optional[_Node]] = [None] * 256
    _build_lookup(lookup, root)

    # node count for minimal tree size
    node_count = root.num_nodes()
    tree_block = _encode_tree(root, node_count)

    out = bytearray()
    header = ((len(data) & 0xFFFFFF) << 8) | 0x28
    out.extend(header.to_bytes(4, byteorder="little"))
    out.extend(tree_block)

    bs = _Bitstream(out)
    for b in data:
        n = lookup[b]
        if n is None:
            raise ValueError("Internal error: missing symbol in lookup")
        bs.push(n.code, n.code_len)
    bs.flush()

    if len(out) % 4:
        out.extend(b"\x00" * (4 - (len(out) % 4)))

    return bytes(out)

