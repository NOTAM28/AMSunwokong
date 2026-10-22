# XNU plan for cuscoi (Moto G96 / SM7435)

## Boot path (LOCKED — do not replace with UEFI yet)
ABL → boot.img v4 (kernel replaced) → shim @ 0x80080000
  → EL1 + identity MMU (1GB L0 @ 0x80000000)
  → staging @ 0xB8400000 (splash FB+4MB)
  → Mach-O load + boot_args @ 0xB8600000 (x0)
  → jump to XNU

## Kernel target
- xnu-8796 (iOS 16.x), same generation as ios-sweet / HackiOS
- Machine name: cuscoi
- Build: GitHub Actions macOS (or real Mac). WSL alone cannot fully link XNU.

## References
- ~/ref-ios-sweet  (or path where ios-sweet was cloned)
- ~/ref-hackios    (optional; UEFI path — ideas only)

## Patch priority (adapt from sweet, retarget MMIO)
1. Toolchain / build for non-Apple arm64
2. Machine config cuscoi (platform expert stub)
3. Early FB console on splash 0xB8000000 1080x2400 BGRA
4. GICv3 0x17200000 / redist 0x17260000
5. Timer 19.2 MHz
6. Physmap / memory from FDT banks
7. Then UFS, SMP, etc.

## ADT
- Apple flattened DT (not Linux FDT)
- Seed from iPhone DeviceTree in IPSW; patch memory-map, GIC, timer, FB, /chosen
- deviceTreeP in boot_args → our staging ADT

## Milestone order
[ ] CI produces kernel.development.cuscoi Mach-O
[ ] mkpayload: kernel + ADT + boot_args into staging layout
[ ] fastboot boot → any XNU code runs (panic OK if FB shows text)
[ ] Survive past arm_init
[ ] Timer + IRQ
[ ] UFS + root
