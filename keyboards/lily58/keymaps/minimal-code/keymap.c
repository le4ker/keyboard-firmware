// Copyright 2023 Panos Sakkos <panos.sakkos@gmail.com> @le4ker
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

#include QMK_KEYBOARD_H

enum layer_number {
    _BASE  = 0,
    _LOWER = 1,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* BASE
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |BackSP|
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  \   |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * | Esc  |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |   '  |
     * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
     * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |Delete|
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *                   | LCtl | LAlt | LGUI | / Space /       \ Enter\  |  -   |  =   |TG(LO)|
     *                   |      |      |      |/       /         \      \ |      |      |      |
     *                   `----------------------------'           '------''--------------------'
     */

    // clang-format off
    [_BASE] = LAYOUT(
                    KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5,              KC_6, KC_7, KC_8, KC_9, KC_0, KC_BSPC,
                    KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T,               KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSLS,
                    KC_ESC, KC_A, KC_S, KC_D, KC_F, KC_G,               KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT,
                 KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_LBRC,     KC_RBRC, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_DEL,
                    KC_LCTL, KC_LALT, KC_LGUI, KC_SPC,                  KC_ENT, KC_MINS, KC_EQL, TG(_LOWER)
    ),
    // clang-format on

    /* LOWER
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |                    |  F7  |  F8  |  F9  | F10  | F11  | F12  |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * | Tab  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |      |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * | Esc  |      |      |      |      |      |-------.    ,-------| Left | Down |  Up  | Right|      |      |
     * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
     * |LShift|      |      |      |      |      |-------|    |-------| Prev | VolDn| VolUp| Next |      |Delete|
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *                   | LCtl | LAlt | LGUI | / Play  /       \ Mute \  | BriDn| BriUp|TG(LO)|
     *                   |      |      |      |/       /         \      \ |      |      |      |
     *                   `----------------------------'           '------''--------------------'
     */

    // clang-format off
    [_LOWER] = LAYOUT(
                    KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6,           KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12,
                    KC_TAB, KC_1, KC_2, KC_3, KC_4, KC_5,               KC_6, KC_7, KC_8, KC_9, KC_0, KC_NO,
                    KC_ESC, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,          KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_NO, KC_NO,
                KC_LSFT, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,  KC_NO, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, KC_NO, KC_DEL,
                    KC_LCTL, KC_LALT, KC_LGUI, KC_MPLY,                 KC_MUTE, KC_BRMD, KC_BRMU, TG(_LOWER))};

// clang-format on

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (!is_keyboard_master()) {
        return OLED_ROTATION_180;
    }

    return rotation;
}

#define L_BASE 0
#define L_LOWER (1 << 1)

bool oled_task_user(void) {
    oled_write("   { minimal-code }\n\n\n     ", false);

    switch (layer_state) {
        case L_BASE:
            oled_write_ln("Layer: Base", false);
            break;

        case L_LOWER:
            oled_write_ln("Layer: Lower", false);
            break;
    }

    return false;
}

// Override unused placeholder functions to save firmware space
uint16_t keycode_config(uint16_t keycode) {
    return keycode;
}

uint8_t mod_config(uint8_t mod) {
    return mod;
}
