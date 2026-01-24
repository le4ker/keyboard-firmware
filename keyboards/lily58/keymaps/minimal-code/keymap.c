// Copyright 2023 Panos Sakkos <panos.sakkos@gmail.com> @le4ker
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR ANY PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

#include QMK_KEYBOARD_H

// Enable matrix scan rate debug output
void keyboard_post_init_user(void) {
    debug_enable = true;
    debug_matrix = true;
}

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
                    KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5,               KC_6, KC_7, KC_8, KC_9, KC_0, KC_BSPC,
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
     * | Tab  |      |      |      |      |      |                    | Prev | VolDn| VolUp| Next |      |      |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * | Esc  |      |      |      |      |      |-------.    ,-------| Left | Down |  Up  | Right|      |      |
     * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
     * |LShift|      |      |      |      |      |-------|    |-------|      | BriDn| BriUp|      |      |Delete|
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *                   | LCtl | LAlt | LGUI | / Play  /       \ Mute \  |      |      |TO(BA)|
     *                   |      |      |      |/       /         \      \ |      |      |      |
     *                   `----------------------------'           '------''--------------------'
     */

    // clang-format off
    [_LOWER] = LAYOUT(
                    KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6,           KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12,
                    KC_TAB, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,          KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, KC_NO, KC_NO,
                    KC_ESC, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,          KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_NO, KC_NO,
                KC_LSFT, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO, KC_NO, KC_BRMD, KC_BRMU, KC_NO, KC_NO, KC_DEL,
                    KC_LCTL, KC_LALT, KC_LGUI, KC_MPLY,                 KC_MUTE, KC_NO, KC_NO, TO(_BASE))};

// clang-format on

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_180;
    }
    return rotation;
}

// 128x32 OLED = 21 chars x 4 lines
static const char PROGMEM base_l1[] = "###   ##   ###  ###  ";
static const char PROGMEM base_l2[] = "#  # #  # #    #     ";
static const char PROGMEM base_l3[] = "###  #### ###  ###   ";
static const char PROGMEM base_l4[] = "###  #  #  ### ###   ";

static const char PROGMEM lower_l1[] = " #     ##  #   #     ";
static const char PROGMEM lower_l2[] = " #    #  # # # #     ";
static const char PROGMEM lower_l3[] = " #    #  # # # #     ";
static const char PROGMEM lower_l4[] = " ####  ##   # #      ";

bool oled_task_user(void) {
    static uint8_t last_layer    = 0xFF;
    uint8_t        current_layer = get_highest_layer(layer_state);

    if (current_layer != last_layer) {
        oled_clear();

        switch (current_layer) {
            case _BASE:
                oled_set_cursor(0, 0);
                oled_write_P(base_l1, false);
                oled_set_cursor(0, 1);
                oled_write_P(base_l2, false);
                oled_set_cursor(0, 2);
                oled_write_P(base_l3, false);
                oled_set_cursor(0, 3);
                oled_write_P(base_l4, false);
                break;
            case _LOWER:
                oled_set_cursor(0, 0);
                oled_write_P(lower_l1, false);
                oled_set_cursor(0, 1);
                oled_write_P(lower_l2, false);
                oled_set_cursor(0, 2);
                oled_write_P(lower_l3, false);
                oled_set_cursor(0, 3);
                oled_write_P(lower_l4, false);
                break;
        }

        last_layer = current_layer;
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
