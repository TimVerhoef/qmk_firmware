#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum _layer {
  _MA,
  _FN
};

// tap dance
enum _keycodes {
  DFU
};

void f_reset(qk_tap_dance_state_t *state, void *user_data) {
  if (state->count >= 3) {
    reset_keyboard();
  }
}

qk_tap_dance_action_t tap_dance_actions[] = {
  [DFU] = ACTION_TAP_DANCE_FN(f_reset)
};

// custom keycodes (CK_*)
#define CK_FN MO(_FN)         // momentarily activate layer _FN
#define CK_SP KC_POWER        // macOS system power
#define CK_VU KC__VOLUP       // macOS volume up
#define CK_VD KC__VOLDOWN     // macOS volume down
#define CK_VM KC__MUTE        // macOS volume mute
#define CK_EJ KC_MEDIA_EJECT  // macOS eject
#define CK_PS KC_PSCREEN      // print screen
#define CK_BD KC_SCROLLLOCK   // macOS brightness down, scroll lock
#define CK_BU KC_PAUSE        // macOS brightness up, pause

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_MA] = LAYOUT_60_ansi_split_bs_rshift(
  KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSLS, KC_GRV, \
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSPC,         \
  KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,                   \
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, CK_FN,                    \
  KC_LCTL, KC_LALT, KC_LGUI,                            KC_SPC,                             KC_RGUI, KC_RALT, KC_RCTL, CK_FN            ),

[_FN] = LAYOUT_60_ansi_split_bs_rshift(
  CK_SP,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_INS,  KC_DEL, \
  KC_CAPS, _______, _______, _______, _______, _______, _______, _______, CK_PS,   CK_BD,   CK_BU,   KC_UP,   _______, KC_CLR,          \
  TD(DFU), CK_VU,   CK_VD,   CK_VM,   CK_EJ,   _______, KC_PAST, KC_PSLS, KC_HOME, KC_PGUP, KC_LEFT, KC_RGHT, _______,                  \
  _______, _______, _______, _______, _______, _______, KC_PPLS, KC_PMNS, KC_END,  KC_PGDN, KC_DOWN, _______, KC_TRNS,                  \
  _______, _______, _______,                            _______,                            KC_STOP, _______, _______, _______          )
};
