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
static tap winctrl_state = {
  .is_press_action = true,
  .state = 0
};

int win_ctrl_cur_dance( qk_tap_dance_state_t *state )
{
  if( state->count == 1 ) {
    return SEND_LGUI;
  }
  else if( state->count == 2 ) {
    return SEND_LCTRL;
  }
  else if( state->count == 3 ) {
    return SEND_LALT;
  }
  return -1;
}

//for the x tap dance. Put it here so it can be used in any keymap
void win_ctrl_finished( qk_tap_dance_state_t *state, void *user_data )
{
  winctrl_state.state = win_ctrl_cur_dance( state );
  switch (winctrl_state.state ) {
    case SEND_LGUI:
      register_code( KC_LGUI ); break;
    case SEND_LCTRL:
      register_code( KC_LCTRL ); break;
    case SEND_LALT:
      register_code( KC_LALT ); break;
  }
}

void win_ctrl_reset( qk_tap_dance_state_t *state, void *user_data )
{
  switch (winctrl_state.state ) {
    case SEND_LGUI:
      unregister_code( KC_LGUI ); break;
    case SEND_LCTRL:
      unregister_code( KC_LCTRL ); break;
    case SEND_LALT:
      unregister_code( KC_LALT ); break;
  }
  winctrl_state.state = 0;
}


// Map LSFT and CAPS
static tap lsftcaps_state = {
  .is_press_action = true,
  .state = 0
};

int lsft_caps_cur_dance( qk_tap_dance_state_t *state )
{
  if( state->count == 1 ) {
    return SEND_LSFT;
  }
  else if( state->count == 2 ) {
    return SEND_CAPS;
  }

  return -1;
}

//for the x tap dance. Put it here so it can be used in any keymap
void lsft_caps_finished( qk_tap_dance_state_t *state, void *user_data )
{
  lsftcaps_state.state = lsft_caps_cur_dance( state );
  switch (lsftcaps_state.state ) {
    case SEND_LSFT:
      register_code( KC_LSFT ); break;
    case SEND_CAPS:
      register_code( KC_CAPSLOCK ); break;
  }
}

void lsft_caps_reset( qk_tap_dance_state_t *state, void *user_data )
{
  switch (lsftcaps_state.state ) {
    case SEND_LSFT:
      unregister_code( KC_LSFT ); break;
    case SEND_CAPS:
      unregister_code( KC_CAPSLOCK ); break;
  }
  lsftcaps_state.state = 0;
}


enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  VRSN,
  RGB_SLD,
  VIM_PASTE_FROM_0_REG // macro corresponding to "0p and "0P
};

// Note: TAP_DANCE_ENABLE = true must be set in rules.mk in ergodox_ez directory
// https://docs.qmk.fm/#/feature_tap_dance
// Tap Dance Declarations
enum {
  TD_MINUS_UNDERSCORE = 0,
  TD_EQUALS_PLUS,
  TD_LTGT,
  TD_PARENS,
  TD_SQUARES,
  TD_CURLIES,
  TD_WIN_CTRL,
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
  [ TD_WIN_CTRL ] =  ACTION_TAP_DANCE_FN_ADVANCED( NULL, win_ctrl_finished, win_ctrl_reset ),
  [ TD_LSFT_CAPS ] =  ACTION_TAP_DANCE_FN_ADVANCED( NULL, lsft_caps_finished, lsft_caps_reset ),
};