#include "kb.h"

//Tap Dance Declarations
enum {
    TD_YAKUAKE
};

//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_YAKUAKE] = ACTION_TAP_DANCE_DOUBLE(KC_GRV, LALT(KC_GRV)),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	KEYMAP(
		KC_ESC, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_PSCR,
		TD(TD_YAKUAKE), KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC,
		KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS,
		KC_CAPS, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, MT(MOD_RCTL, KC_SCLN), KC_QUOT, KC_ENT, KC_DEL,
		KC_LSPO, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSPC, KC_END, KC_HOME,
		KC_LCTL, KC_LGUI, KC_LALT, KC_SPC,

        MOD_HYPR, KC_MUTE, KC_VOLD, KC_VOLU, //4 keys left of space bar

        KC_LEFT, KC_DOWN, KC_RGHT, KC_UP, KC_PGDN, KC_PGUP

        ),
};
// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
}
// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	return true;
}

