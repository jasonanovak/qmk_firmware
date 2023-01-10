#include QMK_KEYBOARD_H

#define _LayerChooser 3

enum custom_keycodes {
    MUTE_VIDEO = SAFE_RANGE,
    MUTE_AUDIO,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case MUTE_VIDEO:
        if (record->event.pressed) {
            SEND_STRING(SS_LCTL("E"));
            _delay_ms(100);
            // when keycode QMKBEST is pressed
//            SEND_STRING("QMK is the best thing ever!");
//        } else {
//            // when keycode QMKBEST is released
        }
        break;

    case MUTE_AUDIO:
        if (record->event.pressed) {
            SEND_STRING(SS_LCTL("D"));
            _delay_ms(100);
//            SS_DELAY(100);

//            LCTL(KC_D);

            // when keycode QMKURL is pressed
//            SEND_STRING("https://qmk.fm/\n");
//        } else {
//            // when keycode QMKURL is released
        }
        break;

    }
    return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [0] = LAYOUT(KC_KB_MUTE, KC_KB_VOLUME_DOWN, KC_KB_VOLUME_UP,
               MUTE_VIDEO, MUTE_AUDIO, KC_NO,
               KC_NO, KC_NO, LT(_LayerChooser,KC_NO)),

  [1] = LAYOUT(RGB_RMOD, RGB_VAI, RGB_MOD,
               RGB_HUI, KC_TRNS, RGB_SAI,
               RGB_HUD, RGB_VAD, LT(_LayerChooser,RGB_SAD)),

  [_LayerChooser] = LAYOUT(TO(0), TO(1), KC_NO,
                           KC_NO, KC_NO, KC_NO,
                           KC_NO, KC_NO, LT(_LayerChooser,KC_NO)),

};
