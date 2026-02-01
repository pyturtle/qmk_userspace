#include QMK_KEYBOARD_H

#define ENT_CMD MT(MOD_LGUI, KC_ENTER)
// export PATH="/Users/nathannguyen/toolchains/arm-gnu-toolchain-12.3.rel1-darwin-arm64-arm-none-eabi/bin:$PATH"
// qmk compile -kb bastardkb/scylla -km nathan

// ——— Keymap layers ———
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[0] = LAYOUT_split_4x6_5(
    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_EQL,
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_UNDS,
    KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
    MT(MOD_LGUI, KC_ESC),
    MO(1),
    MT(MOD_LALT, KC_TAB),
    MT(MOD_LGUI | MOD_LALT, KC_BSPC),
    LT(2, KC_SPC),
    ENT_CMD,
    KC_LALT,
    LCTL(LSFT(KC_Z)),
    LGUI(KC_SPC),
    KC_DEL
),

[1] = LAYOUT_split_4x6_5(
    QK_BOOT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,

    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_TRNS,

    KC_HASH, KC_EXLM, KC_ASTR, KC_PLUS, KC_EQL,  KC_AMPR, KC_CIRC, KC_LPRN, KC_RPRN, KC_LBRC, KC_RBRC, KC_DLR,

    KC_TRNS, KC_TILD, KC_AT,   KC_MINS, KC_PIPE, KC_PERC, KC_UNDS, KC_LCBR, KC_RCBR, KC_LT,   KC_GT,   KC_BSLS,

    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
),


[2] = LAYOUT_split_4x6_5(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_TRNS, KC_MPRV, KC_TRNS, KC_MFFD, KC_BRIU, KC_TRNS,
    KC_TRNS, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_BRID, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_F11,  KC_F12,  KC_TRNS, KC_VOLD, KC_MPLY, KC_VOLU, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
),


    [3] = LAYOUT_split_4x6_5(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_P7,   KC_P8,   KC_P9,   KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_P4,   KC_P5,   KC_P6,   KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_P0,   KC_P1,   KC_P2,   KC_P3,   KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    )
};

// ——— Per-layer underglow color ———
layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
        case 1:  rgblight_sethsv(0,   255, 128); break; // red
        case 2:  rgblight_sethsv(160, 255, 128); break; // blue
        case 3:  rgblight_sethsv(96,  255, 128); break; // green
        default: rgblight_sethsv(0,   0,   255); break; // white
    }
    return state;
}

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case ENT_CMD:
        case MT(MOD_LGUI, KC_ESC):
            return true;
        default:
            return false;
    }
}
