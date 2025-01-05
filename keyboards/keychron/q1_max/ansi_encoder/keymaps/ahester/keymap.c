/* Copyright 2023 @ Keychron (https://www.keychron.com)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include "keychron_common.h"

enum custom_keycodes {
    M_COPY = SAFE_RANGE,
    M_PASTE,
    M_CUT,
    M_ALL,
    M_UNDO,
};

enum layers {
    MAC_BASE,
    MAC_FN,
    WIN_BASE,
    LAYER_2,
    LAYER_3,
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [MAC_BASE] = LAYOUT_ansi_82(
        KC_ESC,   KC_BRID,  KC_BRIU,  KC_MCTRL, KC_LNPAD, RGB_VAD,  RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,  KC_DEL,             KC_MUTE,
        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,            KC_PGUP,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,            KC_PGDN,
        KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,            KC_ENT,             KC_HOME,
        KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,            KC_RSFT,  KC_UP,
        KC_LCTL,  KC_LOPTN, KC_LCMMD,                               KC_SPC,                                 KC_RCMMD,MO(MAC_FN),KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT),

    [MAC_FN] = LAYOUT_ansi_82(
        _______,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   _______,            RGB_TOG,
        _______,  BT_HST1,  BT_HST2,  BT_HST3,  P2P4G,    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
        RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
        _______,  RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,  _______,  _______,  _______,  _______,  _______,  _______,            _______,            KC_END,
        _______,            _______,  _______,  _______,  _______,  BAT_LVL,  NK_TOGG,  _______,  _______,  _______,  _______,            _______,  _______,
        _______,  _______,  _______,                                _______,                                _______,  _______,  _______,  _______,  _______,  _______),

    [WIN_BASE] = LAYOUT_ansi_82(
        KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_DEL,             KC_MUTE,
        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,            KC_PGUP,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,            KC_PGDN,
        KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,            KC_ENT,             KC_HOME,
        KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,            KC_RSFT,  KC_UP,
        KC_LCTL,  KC_LGUI,  KC_LALT,                                KC_SPC,                                 KC_RALT,TO(LAYER_2),KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT),

    [LAYER_2] = LAYOUT_ansi_82(
        _______,  KC_BRID,  KC_BRIU,  KC_TASK,  KC_FILE,  RGB_VAD,  RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,  _______,            RGB_TOG,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
        RGB_TOG,  _______,  _______,  _______,  _______,  _______,  _______,  KC_P7,    KC_P8,    KC_P9,    _______,  _______,  _______,  _______,            _______,
        _______,  M_ALL,    _______,  _______,  _______,  _______,  _______,  KC_P4,    KC_P5,    KC_P6,    _______,  _______,            _______,            KC_END,
        _______,            M_UNDO,   M_CUT,    M_COPY,   M_PASTE,  _______,  KC_P0,    KC_P1,    KC_P2,    KC_P3,    _______,            _______,  _______,
    TO(LAYER_3),  _______,  _______,                                _______,                                _______,TO(WIN_BASE),_______, _______,  _______,  _______),

    [LAYER_3] = LAYOUT_ansi_82(
    TO(WIN_BASE), _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            QK_BOOT,
        _______,  BT_HST1,  BT_HST2,  BT_HST3,  P2P4G,    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
        RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
        _______,  RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,  _______,  _______,  _______,  _______,  _______,  _______,            _______,            _______,
        _______,            _______,  _______,  _______,  _______,  BAT_LVL,  NK_TOGG,  _______,  _______,  _______,  _______,            _______,  _______,
    TO(LAYER_2),  _______,  _______,                                _______,                                _______,TO(WIN_BASE),_______, _______,  _______,  _______)
};

// clang-format on
#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [MAC_BASE] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [MAC_FN]   = {ENCODER_CCW_CW(RGB_VAD, RGB_VAI)},
    [WIN_BASE] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [LAYER_2]  = {ENCODER_CCW_CW(RGB_VAD, RGB_VAI)},
    [LAYER_3]  = {ENCODER_CCW_CW(RGB_VAD, RGB_VAI)},
};
#endif // ENCODER_MAP_ENABLE

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case M_COPY:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("c"));
            } else { // RELEASED
            }
            break;
        case M_PASTE:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("v"));
            } else { // RELEASED
            }
            break;
        case M_CUT:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("x"));
            } else { // RELEASED
            }
            break;
        case M_ALL:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("a"));
            } else { // RELEASED
            }
            break;
        case M_UNDO:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("z"));
            } else { // RELEASED
            }
            break;
    }
    return true;
};


/*
    LED MATRIX
     ESC  F1  F2  F3  F4  F5  F6  F7  F8  F9 F10 F11 F12 DEL
    {  0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, __ }, FN

       `   1   2   3   4   5   6   7   8   9   0   -   = BKSP PGUP
    { 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28 }, NUM

     TAB   Q   W   E   R   T   Y   U   I   O   P   [   ]   \  PGDN
    { 29  30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43 }, QWERTY

     CAPS  A   S   D   F   G   H   J   K   L   ;   '  ENT HOME
    { 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, __ }, ASDF

     SHFT      Z   X   C   V   B   N   M   ,   .   /    SHFT  UP
    { 58, __, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, __, 69, 70 }, ZCXV

    CTRL WIN ALT             SPACE       ALT  FN CTRL LFT DN RGHT
    { 71, 72, 73, __, __, __, 74, __, __, 75, 76, 77, 78, 79, 80 }, CTRL
*/
bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    uint8_t layer = get_highest_layer(layer_state);
    switch(layer) {
        case 4: // LAYER 3
            rgb_matrix_set_color(15, RGB_RED);
            rgb_matrix_set_color(16, RGB_RED);
            rgb_matrix_set_color(17, RGB_RED);
            rgb_matrix_set_color(18, RGB_BLUE);

            rgb_matrix_set_color(30, RGB_BLUE);
            rgb_matrix_set_color(45, RGB_BLUE);
            rgb_matrix_set_color(31, RGB_GREEN);
            rgb_matrix_set_color(46, RGB_GREEN);
            rgb_matrix_set_color(32, RGB_ORANGE);
            rgb_matrix_set_color(47, RGB_ORANGE);
            rgb_matrix_set_color(33, RGB_PURPLE);
            rgb_matrix_set_color(48, RGB_PURPLE);
            rgb_matrix_set_color(33, RGB_YELLOW);
            rgb_matrix_set_color(48, RGB_YELLOW);

            rgb_matrix_set_color(49, RGB_BLUE);
            rgb_matrix_set_color(50, RGB_BLUE);
            rgb_matrix_set_color(63, RGB_BLUE);
            rgb_matrix_set_color(64, RGB_GREEN);
            break;
        case 3: // LAYER 2 
            uint8_t num_pad[12] = {
                22, 23,
                36, 37, 38,
                51, 52, 53,
                64, 65, 66, 67
            };
            for (uint8_t i = 0; i < sizeof(num_pad); i++) {
                rgb_matrix_set_color(num_pad[i], RGB_BLUE);
            }
            uint8_t function[5] = {
                45, 59, 60, 61, 62
            };
            for (uint8_t i = 0; i < sizeof(function); i++) {
                rgb_matrix_set_color(function[i], RGB_MAGENTA);
            }
            break;
        case 2: // LAYER 1 
            if (host_keyboard_led_state().caps_lock) {
                rgb_matrix_set_color(29, RGB_RED);
                rgb_matrix_set_color(30, RGB_RED);
                rgb_matrix_set_color(44, RGB_RED);
                rgb_matrix_set_color(45, RGB_RED);
            }
            break; 
        case 1:
            break; // Mac layer
        case 0:
            break; // Mac layer
        default:
            break;
    }
    return false;
}