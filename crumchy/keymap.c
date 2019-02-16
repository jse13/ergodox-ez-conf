#include QMK_KEYBOARD_H
#include "quantum.h"
#include "process_keycode/process_tap_dance.h"

enum {
    TD_EQUALS_PLUS = 0,
    TD_MINUS_UNDERSCORE,
    TD_LTGT,
    TD_PARENS,
    TD_SQUARES,
    TD_CURLIES
};

qk_tap_dance_action_t tap_dance_actions[] = {
  [ TD_EQUALS_PLUS ] = ACTION_TAP_DANCE_DOUBLE( KC_EQUAL, KC_PLUS ),
  [ TD_MINUS_UNDERSCORE ] = ACTION_TAP_DANCE_DOUBLE( KC_MINUS, KC_UNDS ),
  [ TD_LTGT ] =  ACTION_TAP_DANCE_DOUBLE( KC_LABK, KC_RABK ),
  [ TD_PARENS ] = ACTION_TAP_DANCE_DOUBLE( KC_LPRN, KC_RPRN ),
  [ TD_SQUARES ] =  ACTION_TAP_DANCE_DOUBLE( KC_LBRACKET, KC_RBRACKET ),
  [ TD_CURLIES ] =  ACTION_TAP_DANCE_DOUBLE( KC_LCBR, KC_RCBR ),
  // [ TD_WIN_CTRL_ALT ] =  ACTION_TAP_DANCE_FN_ADVANCED( NULL, win_ctrl_alt_finished, win_ctrl_alt_reset ),
//   [ TD_LSFT_CAPS ] =  ACTION_TAP_DANCE_FN_ADVANCED( NULL, lsft_caps_finished, lsft_caps_reset ),
};

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _FCN 4
#define _NAV 4

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  FCN,
  NAV,
  ITERM_MACRO,
};

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | Alt  |      | Bksp | GUI  |Lower |Raise |Space |Enter |      |      |      |
 * `-----------------------------------------------------------------------------------' */
[_QWERTY] = LAYOUT_ortho_4x12( \
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, \
  KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT , \
  KC_LCTL,  KC_LALT, MO(_LOWER),  KC_BSPC, KC_LGUI, MO(_LOWER),  MO(_RAISE), KC_SPC, KC_ENT, _______, _______, ITERM_MACRO\
),

[_LOWER] = LAYOUT_ortho_4x12( \
  KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC, \
  KC_TILD,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_GRAVE, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,\
  _______, _______, _______, _______, _______, _______, _______, TD( TD_EQUALS_PLUS ), TD( TD_MINUS_UNDERSCORE ), _______, _______, _______\
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO # |ISO / |      |      |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_ortho_4x12( \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,\
  _______, TD( TD_LTGT ), TD( TD_PARENS ), TD( TD_SQUARES ), TD( TD_CURLIES), _______, _______, _______, _______, _______, _______, _______,\
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,\
  _______, _______, _______, _______, _______, MO( _NAV ), _______, _______, _______, _______, _______, _______\
),

/* Fc
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO # |ISO / |      |      |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_FCN] = LAYOUT_ortho_4x12( \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,\
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,\
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,\
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______\
),

/* NAV
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO # |ISO / |      |      |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_NAV] = LAYOUT_ortho_4x12( \
  _______, _______, KC_MS_BTN1, KC_MS_UP,    KC_MS_BTN2, _______,     _______, _______, _______, _______, _______, _______,\
  _______, _______, KC_MS_LEFT, KC_MS_DOWN , KC_MS_RIGHT, _______,    KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, _______, _______,\
  _______, _______, _______, _______, _______, _______,               _______, _______, _______, _______, _______, _______,\
  _______, _______, _______, _______, _______, _______,               _______, _______, _______, _______, _______, _______\
)

};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_qwerty);
        #endif
        persistent_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
      } else {
        layer_off(_LOWER);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
      } else {
        layer_off(_RAISE);
      }
      return false;
      break;
    case ITERM_MACRO:
      if (record->event.pressed) {
        SEND_STRING(SS_LALT(SS_LGUI(SS_TAP(X_SPACE))));
      }
  }
  return true;
}