/* Copyright 2020 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
 * Copyright 2019 Sunjun Kim
 * Copyright 2020 Ploopy Corporation
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H
#include "config.h"

// safe range starts at `PLOOPY_SAFE_RANGE` instead.


/*

Set the array of DPI Options for the mouse.
The range of supported DPIs is X to Y
Default is 750

*/
#define PLOOPY_DPI_OPTIONS { 500, 750, 1000, 1250, 1500 }
#define PLOOPY_DPI_DEFAULT 3

// define layer names
// ChromeOS is default as that's what I use most
#define _ChromeOS 1
#define _Normal 0
#define _KDE 2
#define _Meta 3
#define hold4 4
#define hold5 5
#define _Layers 6

/*

Use a combo so that when clicking
the left thumb lower, left thumb upper, and ring finger
go to the layer chooser layer

*/
const uint16_t PROGMEM LayerChooser[] = {KC_BTN1,
                                         KC_BTN4,
                                         KC_BTN2,
                                         COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    COMBO(LayerChooser, TO(_Layers))
};


/*

Define a tap dance so that single clicking the pinky key
when the layer is correct is copy on click, paste on double click

*/

enum {
    TD_BTN4_BTN5 = 0
};

tap_dance_action_t tap_dance_actions[] = {
    [TD_BTN4_BTN5] = ACTION_TAP_DANCE_DOUBLE(KC_BTN4, KC_BTN5)
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    // LAYOUT( Thumb Bottom, Wheel, Thumb Top, Middle Finger, Ring Finger)

    [_Normal] = LAYOUT(KC_BTN1,
                    KC_BTN3,
                    TD(TD_BTN4_BTN5),
                    KC_BTN2,
                    KC_BTN6
    ),
};
