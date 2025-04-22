    .section .text
    .global dissolve_tiles
    .extern tiles_count
    .extern tilePixels

dissolve_tiles:
    push {r4-r7, lr}     @ Preserve registers

    ldr r1, =tilePixels @ Load pointer to tilePixels
    ldr r3, =tiles_count
    ldr r3, [r3]          @ Load tiles_count value into r3
    mov r3, r3, lsl #3    @ tiles_count * 8 (8 DWORDs per tile)

loop:
    ldr r4, [r1]          @ Load 4 bytes (8 pixels)
    mov r5, r4

    ands r6, r4, #0x0F
    cmp r6, r0            @ Compare with dissolve_i (passed in r0)
    movlt r4, r4, lsl #4
    andlt r4, r4, #0xF0

    ands r6, r5, #0xF0
    cmp r6, r0, lsl #4
    movlt r5, r5, lsr #4
    andlt r5, r5, #0x0F

    orr r4, r4, r5

    str r4, [r1]          @ Store modified value
    add r1, r1, #4        @ Move to next 32-bit word
    subs r3, r3, #1       @ Decrease loop counter
    bne loop

    pop {r4-r7, lr}
    bx lr                 @ Return