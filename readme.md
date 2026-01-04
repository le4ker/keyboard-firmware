# QMK Firmware Fork - Lily58 Minimal Code Layout

[![Lily58](https://img.shields.io/badge/keyboard-Lily58-blue)](https://github.com/kata0510/Lily58)
[![QMK](https://img.shields.io/badge/powered%20by-QMK-orange)](https://qmk.fm/)

This is a personal fork of [QMK Firmware](https://github.com/qmk/qmk_firmware) containing my custom **minimal-code** keymap for the Lily58 split keyboard.

## My Keymap

A performance-optimized, two-layer layout designed for software developers.

| Layer | Description |
|-------|-------------|
| ![Base Layer](.github/images/base.png) | **Base:** QWERTY with all coding symbols accessible |
| ![Lower Layer](.github/images/lower.png) | **Lower:** F-keys, media, VIM-style arrows |

### Highlights

- 🚀 **~1572 Hz** matrix scan rate (vs ~1353 Hz default)
- ⌨️ **1ms USB polling** for minimal input latency
- 📺 **Smart OLED** - only updates on layer change
- 🔒 **NKRO enabled** by default

👉 **[Full documentation](keyboards/lily58/keymaps/minimal-code/README.md)**

## Quick Start

```bash
# Clone this repo
git clone https://github.com/le4ker/qmk-firmware.git
cd qmk-firmware

# Set up QMK
qmk setup

# Build and flash
cd keyboards/lily58/keymaps/minimal-code
make flash
```

## Upstream

This fork is based on [qmk/qmk_firmware](https://github.com/qmk/qmk_firmware). To sync with upstream:

```bash
git remote add upstream https://github.com/qmk/qmk_firmware.git
git fetch upstream
git merge upstream/master
```

## License

GPL-2.0-or-later (see [LICENSE](LICENSE))
