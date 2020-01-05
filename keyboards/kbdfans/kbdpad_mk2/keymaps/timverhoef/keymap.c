/* Copyright 2019 Ryota Goto
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


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_ortho_6x4( /* default layer */
    KC_ESCAPE, KC_TAB,      KC_RSHIFT,      KC_BSPACE,   \
    MO(1),     KC_KP_SLASH, KC_KP_ASTERISK, KC_KP_MINUS, \
    KC_KP_7,   KC_KP_8,     KC_KP_9,        KC_NO,       \
    KC_KP_4,   KC_KP_5,     KC_KP_6,        KC_KP_PLUS,  \
    KC_KP_1,   KC_KP_2,     KC_KP_3,        KC_NO,       \
    KC_KP_0,   KC_NO,       KC_KP_DOT,      KC_KP_ENTER  \
  ),
  [1] = LAYOUT_ortho_6x4( /* 2nd layer */
    RESET,   _______, _______, _______, \
    _______, XXXXXXX, XXXXXXX, XXXXXXX, \
    KC_P,    KC_T,    KC_W,    _______, \
    KC_G,    KC_J,    KC_M,    XXXXXXX, \
    XXXXXXX, KC_A,    KC_D,    _______, \
    XXXXXXX, _______, _______, _______  \
  ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  return true;
}

void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

void led_set_user(uint8_t usb_led) {

}
