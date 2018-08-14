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