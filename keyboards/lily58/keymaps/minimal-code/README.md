# Lily58 Minimal Code Layout

This layout aims to balance muscle memory from a typical QWERTY layout while
having all the keys used for software development at the first layer only.

Features:

- Only one extra toggled layer with arrows, media and brightness keys that
  follow VIM convention and F keys.
- Matrix scan rate is improved from 1353 Hz that the default keymap achieves, to
  1557 Hz.
- [N-Key Rollover](https://en.wikipedia.org/wiki/Key_rollover#n-key_rollover).
- The
  [debounce algorithm](https://docs.qmk.fm/#/feature_debounce_type?id=types-of-debounce-algorithms)
  is Symmetric Eager per Key with 5 ms debounce time.
- The OLED screen shows the current layer and the keymap name in both screens.
- The keylogger functionality has been disabled for security reasons.

## Base Layer

![Base Layer](../../../../.github/images/base.png)

## Lower Layer

![Lower Layer](../../../../.github/images/lower.png)
