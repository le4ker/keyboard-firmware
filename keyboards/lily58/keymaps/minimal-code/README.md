# Lily58 Minimal Code Layout

A performance-optimized, two-layer keymap for the
[Lily58](https://github.com/kata0510/Lily58) split keyboard, designed
specifically for software developers. This layout prioritizes coding efficiency
by placing all essential programming symbols on the base layer while maintaining
familiar QWERTY muscle memory.

## Layers

### Base Layer

The primary layer optimized for coding with direct access to all programming
symbols.

![Base Layer](../../../../.github/images/base.png)

| Feature    | Keys                                         |
| ---------- | -------------------------------------------- |
| Numbers    | Top row (1-0)                                |
| Brackets   | `[` `]` on thumb cluster                     |
| Symbols    | `-` `=` on right thumb, `\` on right pinky   |
| Modifiers  | Left side: Ctrl, Alt, Cmd                    |
| Navigation | Backspace (top right), Delete (bottom right) |

### Lower Layer

Accessed via `TG(Lower)` toggle key. Contains function keys, media controls, and
navigation.

![Lower Layer](../../../../.github/images/lower.png)

| Feature       | Keys                                         |
| ------------- | -------------------------------------------- |
| Function Keys | F1-F12 on top two rows                       |
| Arrow Keys    | VIM-style (H/J/K/L position)                 |
| Media         | Play/Mute on thumbs, Vol/Track on right hand |
| Brightness    | Brightness up/down on bottom row             |

## Features

### Performance Optimizations

| Metric           | Value    | Notes                                   |
| ---------------- | -------- | --------------------------------------- |
| Matrix Scan Rate | ~1569 Hz | Improved from default ~1353 Hz          |
| USB Polling      | 1ms      | Reduced input latency                   |
| Debounce         | 5ms      | Using `sym_eager_pk` algorithm          |
| NKRO             | Enabled  | All simultaneous key presses registered |

**Disabled features to reduce firmware size and improve scan rate:**

- Mouse Keys, Locking Support, Space Cadet, Grave Escape
- Magic Commands, Command Interface
- Action Tapping, One-Shot modifiers/layers, Macros, Functions
- Link Time Optimization (LTO) enabled
- Minimal `printf` implementation

### OLED Display

- **Smart Updates:** Only refreshes when layer changes (avoids expensive writes)
- **Content:** Shows keymap name (`{ minimal-code }`) and active layer
- **Master Half:** Rotated 180° for correct orientation
- **Power Saving:** 60-second timeout with fade-out effect

### Split Keyboard Configuration

- Right half configured as master
- Layer state synchronized between halves
- Keylogger functionality disabled for security

## Building & Flashing

### Prerequisites

- [QMK Firmware](https://docs.qmk.fm/#/newbs_getting_started) environment set up
- QMK CLI installed (`qmk setup`)

### Using the Makefile

Navigate to the keymap directory and use the provided Makefile:

```bash
cd keyboards/lily58/keymaps/minimal-code

# Compile firmware
make compile

# Flash firmware (put keyboard in bootloader mode first)
make flash

# Clean build artifacts
make clean

# Generate JSON from keymap.c (for QMK Configurator)
make json
```

### Using QMK CLI Directly

From the QMK root directory:

```bash
# Compile
qmk compile -kb lily58 -km minimal-code

# Flash
qmk flash -kb lily58 -km minimal-code
```

### Debug Mode & Matrix Scan Rate

To check the matrix scan rate and enable debug output:

1. **Enable console** in `rules.mk`:

   ```makefile
   CONSOLE_ENABLE = yes
   ```

2. **Enable debug flags** in `keymap.c` (add after includes):

   ```c
   void keyboard_post_init_user(void) {
       debug_enable = true;
       debug_matrix = true;
   }
   ```

3. **Flash and monitor**:

   ```bash
   qmk flash -kb lily58/rev1 -km minimal-code
   qmk console
   ```

   The console will display the matrix scan rate in Hz.

4. **Disable when done** to save firmware space:

   ```makefile
   CONSOLE_ENABLE = no
   ```

   And remove or comment out the `keyboard_post_init_user` function.

## File Structure

```
minimal-code/
├── config.h      # Keyboard configuration and feature flags
├── keymap.c      # Layer definitions and OLED code
├── rules.mk      # Build options and feature toggles
├── Makefile      # Convenience build targets
└── README.md     # This file
```

## Customization

### Changing the Master Half

Edit `config.h` and change:

```c
#define MASTER_RIGHT  // Change to MASTER_LEFT if needed
```

### Adjusting Debounce

Edit `config.h`:

```c
#define DEBOUNCE 5  // Increase if experiencing chatter
```

### Modifying OLED Timeout

Edit `config.h`:

```c
#define OLED_TIMEOUT 60000  // Value in milliseconds
```

## License

GPL-2.0-or-later

## Author

[Panos Sakkos](https://github.com/le4ker) ([@le4ker](https://github.com/le4ker))
