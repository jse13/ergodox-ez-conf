#include "ergodox_ez.h"
#include "debug.h"
#include "action_layer.h"
#include "version.h"
#include "quantum.h"
#include "process_keycode/process_tap_dance.h"


#include "keymap_german.h"

#include "keymap_nordic.h"

#include "include/squeench.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* How the ergodox keys are laid out:
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   1    |   2  |   3  |   4  |   5  |   6  |   7  |           |  39  |  40  |  41  |  42  |  43  |  44  |   45   |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |   8    |   9  |  10  |  11  |  12  |  13  |  14  |           |  46  |  47  |  48  |  49  |  50  |  51  |   52   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |   15   |  16  |  17  |  18  |  19  |  20  |------|           |------|  53  |  54  |  55  |  56  |  57  |   58   |
 * |--------+------+------+------+------+------|  27  |           |  59  |------+------+------+------+------+--------|
 * |   21   |  22  |  23  |  24  |  25  |  26  |      |           |      |  60  |  61  |  62  |  63  |  64  |   65   |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |  28  |  29  |  30  |  31  |  32  |                                       |  66  |  67  |  68  |  69  |  70  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,------------.
 *                                        |  33  |  34  |       |  71  |  72 |
 *                                 ,------|------|------|       |------+-----+------.
 *                                 |      |      |  35  |       |  73  |     |      |
 *                                 |  36  |  37  |------|       |------|  75 |  76  |
 *                                 |      |      |  38  |       |  74  |     |      |
 *                                 `--------------------'       `-------------------'
 */

  /* Base layer */
  [0] = LAYOUT_ergodox(
    KC_GRAVE,           KC_1,    KC_2,           KC_3,           KC_4, KC_5,  KC_NUMLOCK,
    KC_TAB,             KC_Q,    KC_W,           KC_E,           KC_R, KC_T,  KC_TRANSPARENT,
    KC_ESCAPE,          KC_A,    KC_S,           KC_D,           KC_F, KC_G,/*[#####]*/
    TD( TD_LSFT_CAPS ), KC_Z,    KC_X,           KC_C,           KC_V, KC_B,  KC_LABK,
      KC_LCTL, KC_LALT, KC_TRANSPARENT, KC_TRANSPARENT, MO(1),
                                                               LCTL(LSFT(KC_B)),           LCTL(LSFT(KC_T)),
                                                  /*[#######]  [###################]*/     KC_TRANSPARENT,
                                                    KC_BSPACE, TD( TD_WIN_CTRL_ALT ),      LCTL(LSFT(KC_TAB)),

    KC_TRANSPARENT, KC_6,           KC_7,           KC_8,           KC_9,           KC_0,      KC_EQUAL,
    KC_TRANSPARENT, KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,      KC_BSLASH,
    /*[#####]*/     KC_H,           KC_J,           KC_K,           KC_L,           KC_SCOLON, KC_QUOTE,
      KC_RABK,      KC_N,           KC_M,           KC_COMMA,       KC_DOT,         KC_SLASH,  KC_TRANSPARENT,
                                    MO(2),          LSFT(KC_PGUP),  LSFT(KC_PGDN),   KC_RALT,   KC_RCTRL,
    LCTL(LALT(KC_MINUS)), LCTL(LSFT(KC_MINUS)),
    LSFT(KC_PGUP),       /*[######]  [######]*/
    LSFT(KC_PGDN),       KC_ENTER, KC_SPACE
  ),

  /* Number row, left-hand numbers, and symbols */
  [1] = LAYOUT_ergodox(
    KC_GRAVE,         KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,   KC_TRANSPARENT,
    KC_TRANSPARENT,   KC_EXLM,        KC_AT,          KC_HASH,        KC_DLR,         KC_PERC, KC_TRANSPARENT,
    KC_TILD,          KC_1,           KC_2,           KC_3,           KC_4,           KC_5,  /*[############]*/
    KC_TRANSPARENT,   KC_6,           KC_7,           KC_8,           KC_9,           KC_0,    KC_TRANSPARENT,
      KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                              KC_TRANSPARENT, KC_TRANSPARENT,
                                                            /*[############]  [############]*/KC_TRANSPARENT,
                                                              KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,

    KC_TRANSPARENT, KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,
    KC_TRANSPARENT, KC_CIRC,        KC_AMPR,        KC_KP_ASTERISK, KC_LPRN,        KC_RPRN,        KC_F12,
  /*[############]*/KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_GRAVE,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                    MO(3),          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, /*[################]  [######################]*/
    KC_TRANSPARENT, TD( TD_EQUALS_PLUS ), TD( TD_MINUS_UNDERSCORE )
  ),

  /* Paired symbols and right-hand numbers */
  [2] = LAYOUT_ergodox(
    KC_TRANSPARENT,        KC_TRANSPARENT, KC_TRANSPARENT,  KC_TRANSPARENT,   KC_TRANSPARENT,   KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT,        KC_TRANSPARENT, KC_TRANSPARENT,  KC_TRANSPARENT,   KC_TRANSPARENT,   KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT,        TD( TD_LTGT ),  TD( TD_PARENS ), TD( TD_SQUARES ), TD( TD_CURLIES ), KC_TRANSPARENT,/*[###########]*/
    KC_TRANSPARENT,        KC_RABK,        KC_RPRN,         KC_RBRACKET,      KC_RCBR,          KC_TRANSPARENT, KC_TRANSPARENT,
           KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,  KC_TRANSPARENT,   MO(4),
                                                                                    KC_TRANSPARENT, KC_TRANSPARENT,
                                                                  /*[############]  [############]*/KC_TRANSPARENT,
                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,

    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,       KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, VIM_PASTE_FROM_0_REG, KC_TRANSPARENT,
                    KC_1,           KC_2,           KC_3,           KC_4,           KC_5,                 KC_TRANSPARENT,
    KC_TRANSPARENT, KC_6,           KC_7,           KC_8,           KC_9,           KC_0,                 KC_DOT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT,  KC_TRANSPARENT,
    KC_TRANSPARENT,/*[############] [############]*/
    KC_TRANSPARENT,  KC_TRANSPARENT,KC_TRANSPARENT
  ),

  /* Function key hell */
  [3] = LAYOUT_ergodox(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          KC_F6,       /*[#############]*/
    KC_F13,         KC_F14,         KC_F15,         KC_F16,         KC_F17,         KC_F18,         KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                     KC_TRANSPARENT, KC_TRANSPARENT,
                                                                   /*[############] [#############]*/KC_TRANSPARENT,
                                                                     KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,

    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
  /*[############]*/KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,         KC_F12,
    KC_TRANSPARENT, KC_F19,         KC_F20,         KC_F21,         KC_F22,         KC_F23,         KC_F24,
                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT,/*[############]  [############]*/
    KC_TRANSPARENT,  KC_TRANSPARENT, KC_TRANSPARENT
  ),

  /* Navigation layer */
  [4] = LAYOUT_ergodox(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,  KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_BTN1,     KC_MS_UP,       KC_MS_BTN2,     KC_TRANSPARENT,  KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_RIGHT,    KC_TRANSPARENT,/*[############]*/
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,  KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                    KC_TRANSPARENT, KC_TRANSPARENT,
                                                                  /*[############] [#############]*/KC_TRANSPARENT,
                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,

    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
  /*[############]*/KC_LEFT,        KC_DOWN,        KC_UP,          KC_RIGHT,       KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_MS_WH_LEFT,  KC_MS_WH_DOWN,  KC_MS_WH_UP,    KC_MS_WH_RIGHT, KC_TRANSPARENT, KC_TRANSPARENT,
                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT,/*[############]  [############]*/
    KC_TRANSPARENT,  KC_TRANSPARENT, KC_TRANSPARENT
  ),

};

const uint16_t PROGMEM fn_actions[] = {
  [1] = ACTION_LAYER_TAP_TOGGLE(1)
};

// leaving this in place for compatibilty with old keymaps cloned and re-compiled.
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
      switch(id) {
        case 0:
        if (record->event.pressed) {
          SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        }
        break;
      }
    return MACRO_NONE;
};

void matrix_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
  rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // dynamically generate these.
    case EPRM:
      if (record->event.pressed) {
        eeconfig_init();
      }
      return false;
      break;
    case VRSN:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      return false;
      break;
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
      break;
    case VIM_PASTE_FROM_0_REG :
      if( record->event.pressed ) {
        if( keyboard_report->mods & (MOD_BIT( KC_LSFT ) ) ) // Check to see if SHIFT is pressed
          SEND_STRING( "\"0P" );
        else
          SEND_STRING( "\"0p" );
      }
    
  }
  return true;
}

uint32_t layer_state_set_user(uint32_t state) {

    uint8_t layer = biton32(state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      case 0:
        #ifdef RGBLIGHT_COLOR_LAYER_0
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
        #endif
        break;
      case 1:
        ergodox_right_led_1_on();
        #ifdef RGBLIGHT_COLOR_LAYER_1
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
        #endif
        break;
      case 2:
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_2
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
        #endif
        break;
      case 3:
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_3
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
        #endif
        break;
      case 4:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_4
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_4);
        #endif
        break;
      case 5:
        ergodox_right_led_1_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_5
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_5);
        #endif
        break;
      case 6:
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_6
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      case 7:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_7
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      default:
        break;
    }
    return state;

};
