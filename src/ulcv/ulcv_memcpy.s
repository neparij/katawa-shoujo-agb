@ ULCV fast memory copy routines (lifted from src/dxtvplayer/memcpy_funcs.s).
@
@ The simple `for (i = 0; i < N; ++i) dst[i] = src[i];` loop on ARM7TDMI
@ is dominated by EWRAM bus latency: each 32-bit access is 6 cycles, plus
@ ~5 cycles of loop overhead. By using ldmia/stmia in 32-byte (8-word)
@ chunks we eliminate the loop overhead and let the bus burst sequentially.
@
@ Profiling showed the naive loop using ~18% of total frame time for the
@ EWRAM->VRAM blit alone; ldmia/stmia roughly halves that.

@ === void ulcv_memcpy32(void *dst, const void *src, u32 wcount); =====================
@ r0, r1: dst, src
@ r2: wcount, then wcount>>3
@ r3-r10: data buffer
@ r12: wcount & 7
.section .iwram,"ax", %progbits
.arm
.cpu arm7tdmi
.align  2
.global ulcv_memcpy32
.type ulcv_memcpy32 STT_FUNC;
ulcv_memcpy32:
	and		r12, r2, #7
	movs	r2, r2, lsr #3
	beq		.Lulcv_res_cpy32
	push	{r4-r10}
	@ copy 32-byte chunks with 8-fold ldmia/stmia
.Lulcv_main_cpy32:
		ldmia	r1!, {r3-r10}
		stmia	r0!, {r3-r10}
		subs	r2, r2, #1
		bhi		.Lulcv_main_cpy32
	pop		{r4-r10}
	@ residual 0-7 words
.Lulcv_res_cpy32:
		subs	r12, r12, #1
		ldmcsia	r1!, {r3}
		stmcsia	r0!, {r3}
		bhi		.Lulcv_res_cpy32
	bx	lr
.size	ulcv_memcpy32, .-ulcv_memcpy32
