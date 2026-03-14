# QMK Firmware — Lily58 Minimal-Code Keymap

Personal QMK firmware fork for the [Lily58](https://github.com/kata0510/Lily58)
split keyboard. The primary artifact is the `minimal-code` keymap, targeting two
hardware variants.

## Hardware Variants

| Variant            | MCU                    | File                                       |
| ------------------ | ---------------------- | ------------------------------------------ |
| `lily58/rev1`      | ATmega32U4 (Pro Micro) | `keyboards/lily58/rev1/keyboard.json`      |
| `lily58/lite_rev3` | RP2040                 | `keyboards/lily58/lite_rev3/keyboard.json` |

Right half is master (`MASTER_RIGHT` in `config.h`).

## Keymap Source

All keymap files live in:

```
keyboards/lily58/keymaps/minimal-code/
├── keymap.c      # Layer definitions and OLED rendering
├── config.h      # Hardware and feature configuration
├── rules.mk      # Build flags and feature toggles
├── Makefile      # Convenience targets (compile, flash, clean, json)
└── README.md     # Layer diagrams, performance metrics, customization guide
```

## Build & Flash

From the keymap directory:

```bash
make compile   # qmk compile -kb lily58 -km minimal-code
make flash     # qmk flash -kb lily58 -km minimal-code (put board in bootloader first)
make clean     # qmk clean
make json      # generate minimal-code.json for QMK Configurator
```

To target a specific variant directly:

```bash
qmk compile -kb lily58/rev1 -km minimal-code
qmk compile -kb lily58/lite_rev3 -km minimal-code
```

## Design Philosophy

This keymap is explicitly named "minimal-code" — keep it that way. Disabled by
intent:

**In `rules.mk`:**

- `MOUSEKEY_ENABLE = no`
- `LOCKING_SUPPORT_ENABLE = no`
- `SPACE_CADET_ENABLE = no`
- `GRAVE_ESC_ENABLE = no`
- `MAGIC_ENABLE = no`
- `COMMAND_ENABLE = no`
- `LTO_ENABLE = yes` — link-time optimization for size/speed
- `AVR_USE_MINIMAL_PRINTF = yes`

**In `config.h`:**

- `NO_ACTION_TAPPING` — no tap dance, tap-hold, etc.
- `NO_ACTION_ONESHOT` — no one-shot keys/layers
- `NO_ACTION_MACRO` / `NO_ACTION_FUNCTION`
- `LAYER_STATE_8BIT` — limits to 8 layers max, saves space

Do not add features without removing others to compensate. The target is maximum
scan rate and minimal firmware size.

## Layers

- `_BASE` (0): Standard QWERTY with coding symbols on base, `TG(_LOWER)` on
  right thumb
- `_LOWER` (1): F-keys, arrow keys (VIM hjkl position), media/brightness,
  `TO(_BASE)` to return

## OLED

- 128×32 display (21 chars × 4 lines)
- Only redraws on layer change — avoids expensive writes mid-scan
- Master half rotated 180°
- ASCII art shows active layer name (`BASE` / `LOWE`)
- 60s timeout with slowest fade-out (`OLED_FADE_OUT_INTERVAL 15`)

## Performance Metrics

| Metric           | Value                             |
| ---------------- | --------------------------------- |
| Matrix scan rate | ~1569 Hz                          |
| USB polling      | 1ms (`USB_POLLING_INTERVAL_MS 1`) |
| Debounce         | 5ms `sym_eager_pk`                |
| NKRO             | enabled by default                |

## Debugging Matrix Scan Rate

1. Set `CONSOLE_ENABLE = yes` in `rules.mk` (the `#if defined(CONSOLE_ENABLE)`
   guard in `config.h` auto-enables `DEBUG_MATRIX_SCAN_RATE`)
2. Flash and run `qmk console`
3. Set back to `no` before committing — console costs scan rate

## Key Files Outside the Keymap

- `keyboards/lily58/config.h` — sets the OLED font for the whole keyboard
- `keyboards/lily58/lite_rev3/config.h` — RP2040-specific: bootloader, USART,
  I2C
- `keyboards/lily58/lite_rev3/keyboard.json` — RP2040 pin assignments
- `keyboards/lily58/rev1/keyboard.json` — AVR pin assignments

## License

GPL-2.0-or-later. All `.c` and `.h` files must have a GPL2+ header.
