int win_ctrl_alt_cur_dance( qk_tap_dance_state_t *state )
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
void win_ctrl_alt_finished( qk_tap_dance_state_t *state, void *user_data )
{
  winctrlalt_state.state = win_ctrl_alt_cur_dance( state );
  switch (winctrlalt_state.state ) {
    case SEND_LGUI:
      register_code( KC_LGUI ); break;
    case SEND_LCTRL:
      register_code( KC_LCTRL ); break;
    case SEND_LALT:
      register_code( KC_LALT ); break;
  }
}

void win_ctrl_alt_reset( qk_tap_dance_state_t *state, void *user_data )
{
  switch (winctrlalt_state.state ) {
    case SEND_LGUI:
      unregister_code( KC_LGUI ); break;
    case SEND_LCTRL:
      unregister_code( KC_LCTRL ); break;
    case SEND_LALT:
      unregister_code( KC_LALT ); break;
  }
  winctrlalt_state.state = 0;
}