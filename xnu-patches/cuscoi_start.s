/* Minimal kernel entry for open CUSCOI build */
.globl__start
.globl_start
.align2
__start:
_start:
movx19, x0
movx29, xzr
movx30, xzr
movx0, x19
bl_arm_init
1:b1b
