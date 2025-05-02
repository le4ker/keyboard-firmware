# MCU name
MCU = atmega32u4

# Bootloader selection
BOOTLOADER = caterina

# Build Options
BOOTMAGIC_ENABLE = no       # Enable Bootmagic Lite
MOUSEKEY_ENABLE = no        # Mouse keys (Disabled for minimal size)
EXTRAKEY_ENABLE = yes       # Audio control and System control (Keep for keymap)
CONSOLE_ENABLE = no         # Console for debug
COMMAND_ENABLE = no         # Commands for debug and configuration
NKRO_ENABLE = yes           # Enable N-Key Rollover (Keep for keymap)
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
RGBLIGHT_ENABLE = no        # Enable keyboard RGB underglow
AUDIO_ENABLE = no           # Audio output
SPLIT_KEYBOARD = yes        # Compile code for split keyboards
LTO_ENABLE = yes            # Link time optimization is required

# Disable Lock key LEDs if not needed
LOCKING_SUPPORT_ENABLE = no # (Disabled for minimal size)
LOCKING_RESYNC_ENABLE = no  # (Disabled for minimal size)

# Select the keyboard layout (ansi, iso, etc)
LAYOUT = LAYOUT_lily58

# Disable features to save space
TAP_DANCE_ENABLE = no       # Tap Dance
COMBO_ENABLE = no           # Combos
UNICODE_ENABLE = no         # Unicode
POINTING_DEVICE_ENABLE = no # Pointing Device
KEY_OVERRIDE_ENABLE = no    # Key Override 