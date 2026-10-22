# First-wave patches (from ios-sweet → cuscoi)

## Apply order
Same numeric order as filenames. Sweet names stay until we rename.

## Must retarget for SM7435 / cuscoi
| Patch | What to change |
|-------|----------------|
| 0004 machine-config | product name sweet → cuscoi; board ids |
| 0003 / 0010 FB console | base 0xB8000000, 1080×2400, stride 1080*4, BGRA |
| 0016 PE / device-tree | GIC 0x17200000, redist 0x17260000, timer 19.2 MHz |
| 0017 virtual-timer-irq | IRQ numbers from parrot/amxbr DTS |
| 0018 boot-cpu | PSCI / MPIDR if present; single-core first is OK |

## Leave as-is for first link
0001–0002 clang, 0005 non-PAC, 0006–0009 stubs/exports, 0011–0012 physmap/console

## Not in this wave (later)
UFS, mockfs, AMFI, USB, SMP 8-core, touch, display power

## MMIO reference (from our DTS work)
- Splash FB: 0xB8000000 size 0x2B00000
- GIC dist: 0x17200000
- GIC redist: 0x17260000 (confirm in parrot.dts)
- Timer: 19.2 MHz
- UFS: 0x1d84000 (after first boot)

## Applied renames (this session)
- 0004-cuscoi-machine-config.patch  (SWEET → CUSCOI)
- 0003-cuscoi-framebuffer-serial-console.patch  (cuscoi-fbcon, SERIAL_CUSCOI_FBCON)
- 0010-cuscoi-early-framebuffer-debug.patch  (FB base 0xB8000000)

## FB contract for ADT / shim
- phys base: 0xB8000000
- width: 1080
- height: 2400
- stride: 4320  (1080 * 4)
- format: 32bpp BGRA (same as continuous splash)
- ADT node name: cuscoi-fbcon (must match 0003)

## Still original sweet names (edit later if needed)
0016, 0017, 0018 — PE / timer / boot-cpu (grep GIC/timer after we open them)

## GIC (parrot.dts confirmed)
- Distributor:   0x17200000  len 0x10000
- Redistributor: 0x17260000  len 0x100000
- Virtual timer INTID: 19 (PPI; CUSCOI_VTIMER_INTID)
- IPI SGI: 1
- Optional ADT prop: virtual-timer-intid (override)

## 0016 / 0017
- Renamed to cuscoi; PE IONameMatch motorola,cuscoi
- No hard-coded GIC base in those patches (comes from ADT + HAS_GIC_V3 board header)
