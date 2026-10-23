/* Minimal kernel entry for open CUSCOI build — real XNU start.s is machine-config gated */
.globl__start
.globl_start
.align2
__start:
_start:
/* x0 = boot_args* from shim; keep it */
movx19, x0
/* clear frame; set a temporary SP if needed by arm_init path */
movx29, xzr
movx30, xzr
movx0, x19
bl_arm_init
1:b1b
