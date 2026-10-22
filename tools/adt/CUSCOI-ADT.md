# Minimal ADT for cuscoi (first XNU boot)

## Placement (shim already uses these)
- ADT phys: 0xB8500000  (or whatever deviceTreeP in boot_args points to)
- boot_args: 0xB8600000
- FB splash: 0xB8000000

## Required nodes / properties

### Root
- compatible / model: "Motorola,cuscoi" or "cuscoi"
- #address-cells / #size-cells as needed by PE

### cuscoi-fbcon  (MUST match patch 0003)
- name = "cuscoi-fbcon"
- reg or address = 0xB8000000 (phys base)
- width = 1080 (u32)
- height = 2400 (u32)
- stride = 4320 (u32, bytes/line)
- depth = 32 (optional)

### interrupt-controller (GICv3)
- reg: dist 0x17200000 size 0x10000
- reg: redist 0x17260000 size 0x100000
- compatible style matching sweet/XNU GIC path
- virtual-timer-intid = 19 (u32) if PE reads it (patch 0017)

### timer / arch timer
- clock-frequency = 19200000 (if required)
- interrupt for virtual timer → INTID 19

### memory / memory-map
- usable DRAM banks (from FDT / probe; start with 0x80000000 size ~2–3GB if known)
- exclude splash region if needed so kernel does not reclaim FB as free RAM

### chosen
- boot-args string pointer or empty
- any sweet-compatible keys the PE expects

## Out of scope for v0
UFS, display panel beyond FB, touch, PMIC, full SoC tree

## Built artifact
- tools/adt/cuscoi.adt  (~9916 bytes) via tools/mkadt_cuscoi.py
- Real Apple SecureDT format (adt.serialize)
- compatible includes motorola,cuscoi + qcom,sm7435 (matches PE 0016)
- cuscoi-fbcon: reg 0xb8000000 size 0x2b00000, 1080x2400 stride 4320
- GICD/GICR: 0x17200000 / 0x17260000

## Known follow-ups
- chosen dram-base 0xb0000000 may overlap splash 0xb8000000 — split memory-map before heavy pmap use
- Optional: d22ap.adt for /product (userland identity only)
- Shim must set deviceTreeP → phys of this blob (e.g. 0xB8500000)
