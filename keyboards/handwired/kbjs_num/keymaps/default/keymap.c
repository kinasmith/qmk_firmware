#include "kb.h"


// #if defined(RGBLIGHT_ENABLE) && defined(RGBLIGHT_LAYERS)
// static uint32_t rgb_preview_timer = 0;
// #endif
extern rgblight_config_t rgblight_config;


//Tap Dance Declarations
enum {
  TD_ESC_NMLK,
  TD_LAYER_HOME,
  TD_FULLSCREEN,
};



//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    //Tap once for Esc, twice for Caps Lock
    [TD_ESC_NMLK]  = ACTION_TAP_DANCE_DOUBLE(KC_ESC, KC_NUMLOCK),
    [TD_LAYER_HOME] = ACTION_TAP_DANCE_LAYER_MOVE(KC_ESC, 0),
    [TD_FULLSCREEN] = ACTION_TAP_DANCE_DOUBLE(C(G(KC_UP)), KC_F11),

};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = KEYMAP(
		LT(3, KC_ESC),  KC_SLSH,    KC_ASTR,    KC_MINUS,
		KC_7,           KC_8,       KC_9,       KC_PLUS,
		KC_4,           KC_5,       KC_6,
		KC_1,           KC_2,       KC_3,       LT(1, KC_ENT),
		KC_0,                       KC_PDOT
        ),
    [1] = KEYMAP(
        KC_TRNS,    KC_NO,      KC_NO,        KC_NO,
        KC_HOME,    KC_UP,      KC_PGUP,      KC_NO,
        KC_LEFT,    KC_DOWN,    KC_RIGHT,
        KC_END,     KC_DOWN,    KC_PGDN,      KC_LALT,
        KC_LSHIFT,              KC_LCTRL
        ),
    [2] = KEYMAP(
        KC_TRNS,        KC_NO,              KC_NO,      G(C(KC_LEFT)),
        G(A(KC_LEFT)),    G(KC_UP),           G(A(KC_RIGHT)),  G(C(KC_RIGHT)),
        G(KC_LEFT),     TD(TD_FULLSCREEN),  G(KC_RIGHT),
        KC_NO,          G(KC_DOWN),         KC_NO,      KC_LSHIFT,
        G(KC_PGDN),                         KC_NO
        ),
    [3] = KEYMAP(
        KC_TRNS,            RGB_HUI,            RGB_SAI,RGB_VAI,
        RGB_MODE_RAINBOW,   RGB_MODE_SWIRL,     RGB_MODE_SNAKE,     RGB_MODE_FORWARD,
        RGB_MODE_KNIGHT,    RGB_MODE_BREATHE,   RGB_MODE_GRADIENT,
        TO(1),              TO(2),              TO(3),              KC_LSFT,
        TO(0),                                  RGB_MODE_PLAIN
        )
};

void matrix_init_user(void) {
    rgblight_enable();
    rgblight_sethsv(0,0,25);
    rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
}

void matrix_scan_user(void) {
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	return true;
}

void keyboard_pre_init_user(void) {
    rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT);
    // Set our LED pins as output
    // setPinOutput(B2);
    // setPinOutput(B3);
}

bool led_update_user(led_t led_state) {
    rgblight_set_layer_state(0, led_state.caps_lock);
    return true;
}

// bool led_update_kb(led_t led_state) {
//     bool res = led_update_user(led_state);
//     if(res) {
        // writePin(B2, led_state.num_lock); //LED Under NUM Lock Key
        // writePin(B3, led_state.caps_lock); //LED Under Minus Key
        // rgblight_set_layer_state(0, led_state.caps_lock);
//     }
//     return res;
// }
// define HSV_GOLD 36, 255, 255
// #define HSV_GREEN 85, 255, 255
const rgblight_segment_t PROGMEM capslock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 4, HSV_RED},       // Light 4 LEDs, starting with LED 6
    {9, 4, HSV_RED}
);
const rgblight_segment_t PROGMEM layer1_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {4, 3, 85, 255, 150}
);
const rgblight_segment_t PROGMEM layer2_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {4, 3, 36, 255, 190}
    // {3, 1, 186, 255, 100}, //Gold color with brightness knocked down a little
    // {7, 1, 246, 255, 100}
);
const rgblight_segment_t PROGMEM layer3_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 1, HSV_MAGENTA},
    {10, 1, HSV_MAGENTA}
);
const rgblight_segment_t* const PROGMEM rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    capslock_layer,
    layer1_layer,
    layer2_layer,
    layer3_layer
);

layer_state_t layer_state_set_user(layer_state_t state) {
    // Both layers will light up if both kb layers are active
    rgblight_set_layer_state(1, layer_state_cmp(state, 1));
    rgblight_set_layer_state(2, layer_state_cmp(state, 2));
    rgblight_set_layer_state(3, layer_state_cmp(state, 3));
    return state;
}


void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = rgb_layers;
    layer_state_set_user(layer_state);
}
