/* Provides linker entry __start for open CUSCOI builds */
extern void arm_init(void *boot_args);

void cuscoi_kernel_entry(void *boot_args) __asm__("__start");
void cuscoi_kernel_entry(void *boot_args) {
    arm_init(boot_args);
    for (;;) { }
}
