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

*/
#define PLOOPY_DPI_OPTIONS { 500, 750, 1000, 1250, 1500 }
// 3 for Ploopy Classic; 4 for Ploopy Classic 2
#define PLOOPY_DPI_DEFAULT 4

// define layer names to use in the future
#define _Normal 0

/*
 *
Define a tap dance so that single clicking the upper thumb button
is button 4, and double clicking it is button 5.

*/

enum {
    TD_BTN4_BTN5 = 0
};

tap_dance_action_t tap_dance_actions[] = {
    [TD_BTN4_BTN5] = ACTION_TAP_DANCE_DOUBLE(MS_BTN4, MS_BTN5)
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    // LAYOUT( Thumb Bottom, Wheel, Thumb Top, Middle Finger, Ring Finger)

    [_Normal] = LAYOUT(MS_BTN1,
                    MS_BTN3,
                    TD(TD_BTN4_BTN5),
                    MS_BTN2,
                    MS_BTN6
    ),
};
