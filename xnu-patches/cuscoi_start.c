/* Minimal kernel entry for open CUSCOI — provides __start for the linker */
extern void arm_init(void *boot_args);

void __start(void *boot_args) {
    arm_init(boot_args);
    for (;;) { }
}

void _start(void *boot_args) {
    __start(boot_args);
}
