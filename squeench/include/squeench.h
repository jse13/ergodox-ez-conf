#include "quantum.h"
#include "process_keycode/process_tap_dance.h"

typedef struct {
  bool is_press_action;
  int state;
} tap;

enum {
  SEND_LGUI = 1,
  SEND_LCTRL = 2,
  SEND_LALT = 3,
  SEND_LSFT = 4,
  SEND_CAPS = 5
};

// Map LGUI, LCTRL, and LALT to the same
static tap winctrlalt_state = {
  .is_press_action = true,
  .state = 0
};

// Include functions for advanced tapdance functions
#include "win_ctrl_alt_td.h"
#include "lsft_caps_td.h"

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  VRSN,
  RGB_SLD,
  VIM_PASTE_FROM_0_REG // macro corresponding to "0p and "0P
};

// Note: TAP_DANCE_ENABLE = true must be set in qmk_firmware/keyboards/ergodox_ez/rules.mk
// https://docs.qmk.fm/#/feature_tap_dance
// Tap Dance Declarations
enum {
  TD_MINUS_UNDERSCORE = 0,
  TD_EQUALS_PLUS,
  TD_LTGT,
  TD_PARENS,
  TD_SQUARES,
  TD_CURLIES,
  TD_WIN_CTRL_ALT,
  TD_LSFT_CAPS
};

// Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  [ TD_MINUS_UNDERSCORE ] = ACTION_TAP_DANCE_DOUBLE( KC_MINUS, KC_UNDS ),
  [ TD_EQUALS_PLUS ] = ACTION_TAP_DANCE_DOUBLE( KC_EQUAL, KC_PLUS ),
  [ TD_LTGT ] =  ACTION_TAP_DANCE_DOUBLE( KC_LABK, KC_RABK ),
  [ TD_PARENS ] = ACTION_TAP_DANCE_DOUBLE( KC_LPRN, KC_RPRN ),
  [ TD_SQUARES ] =  ACTION_TAP_DANCE_DOUBLE( KC_LBRACKET, KC_RBRACKET ),
  [ TD_CURLIES ] =  ACTION_TAP_DANCE_DOUBLE( KC_LCBR, KC_RCBR ),
  [ TD_WIN_CTRL_ALT ] =  ACTION_TAP_DANCE_FN_ADVANCED( NULL, win_ctrl_alt_finished, win_ctrl_alt_reset ),
  [ TD_LSFT_CAPS ] =  ACTION_TAP_DANCE_FN_ADVANCED( NULL, lsft_caps_finished, lsft_caps_reset ),
};