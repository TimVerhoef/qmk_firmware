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

enum {
  ABC = 0,
  DEF,
  GHI,
  JKL,
  MNO,
  PQRS,
  TUV,
  WXYZ
};

void f_abc(qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    tap_code(KC_A);
  } else if (state->count == 2) {
    tap_code(KC_B);
  } else if (state->count == 3) {
    tap_code(KC_C);
  }
  reset_tap_dance(state);
}

void f_def(qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    tap_code(KC_D);
  } else if (state->count == 2) {
    tap_code(KC_E);
  } else if (state->count == 3) {
    tap_code(KC_F);
  }
  reset_tap_dance(state);
}

void f_ghi(qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    tap_code(KC_G);
  } else if (state->count == 2) {
    tap_code(KC_H);
  } else if (state->count == 3) {
    tap_code(KC_I);
  }
  reset_tap_dance(state);
}

void f_jkl(qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    tap_code(KC_J);
  } else if (state->count == 2) {
    tap_code(KC_K);
  } else if (state->count == 3) {
    tap_code(KC_L);
  }
  reset_tap_dance(state);
}

void f_mno(qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    tap_code(KC_M);
  } else if (state->count == 2) {
    tap_code(KC_N);
  } else if (state->count == 3) {
    tap_code(KC_O);
  }
  reset_tap_dance(state);
}

void f_pqrs(qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    tap_code(KC_P);
  } else if (state->count == 2) {
    tap_code(KC_Q);
  } else if (state->count == 3) {
    tap_code(KC_R);
  } else if (state->count == 4) {
    tap_code(KC_S);
  }
  reset_tap_dance(state);
}

void f_tuv(qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    tap_code(KC_T);
  } else if (state->count == 2) {
    tap_code(KC_U);
  } else if (state->count == 3) {
    tap_code(KC_V);
  }
  reset_tap_dance(state);
}

void f_wxyz(qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    tap_code(KC_W);
  } else if (state->count == 2) {
    tap_code(KC_X);
  } else if (state->count == 3) {
    tap_code(KC_Y);
  } else if (state->count == 4) {
    tap_code(KC_Z);
  }
  reset_tap_dance(state);
}

qk_tap_dance_action_t tap_dance_actions[] = {
  [ABC]  = ACTION_TAP_DANCE_FN(f_abc),
  [DEF]  = ACTION_TAP_DANCE_FN(f_def),
  [GHI]  = ACTION_TAP_DANCE_FN(f_ghi),
  [JKL]  = ACTION_TAP_DANCE_FN(f_jkl),
  [MNO]  = ACTION_TAP_DANCE_FN(f_mno),
  [PQRS] = ACTION_TAP_DANCE_FN(f_pqrs),
  [TUV]  = ACTION_TAP_DANCE_FN(f_tuv),
  [WXYZ] = ACTION_TAP_DANCE_FN(f_wxyz)
};

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
    TD(RESET), _______,   _______,   _______, \
    _______,   XXXXXXX,   XXXXXXX,   XXXXXXX, \
    TD(PQRS),  TD(TUV),   TD(WXYZ),  _______, \
    TD(GHI),   TD(JKL),   TD(MNO),   XXXXXXX, \
    XXXXXXX,   TD(ABC),   TD(DEF),   _______, \
    XXXXXXX,   _______,   _______,   _______  \
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
