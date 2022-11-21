/* Copyright 2021 Jordan Duabe
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

#ifdef OLED_ENABLE
#include QMK_KEYBOARD_H

static void render_logo(void) {
    // static const char PROGMEM qmk_logo[] = {
    //     0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
    //     0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
    //     0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0
    // };
    static const char PROGMEM raw_logo[] = {
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,192,128,128,193, 97, 51, 18, 16,  8,  8,  8, 11, 15, 14, 30, 30, 60,252,158,111,237,249,127,230,194,200,224,241,248,248,248,188, 60, 30, 14,  7,131,129,  0,192,128,128,193, 97, 51, 18, 16,  8,  8,  8, 11, 15, 14, 30, 30, 60,252,158,111,237,249,127,230,194,200,224,241,248,248,248,188, 60, 30, 14,  7,131,129,  0,192,128,128,193, 97, 51, 18, 16,  8,  8,  8, 11, 15, 14, 30, 30, 60,252,158,111,237,249,127,230,194,200,224,241,248,248,248,188, 60, 30, 14,  7,131,129,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,131,  7, 63,192,  0,  0,  0,  0,  0,  0,  0,128,128,  0,  0,128,224,255,241,238,239,255,254,159, 15, 47,159,255,255,255,255,191,128,  4,  6,  3,  3,  3,  0,131,  7, 63,192,  0,  0,  0,  0,  0,  0,  0,128,128,  0,  0,128,224,255,241,238,239,255,254,159, 15, 47,159,255,255,255,255,191,128,  4,  6,  3,  3,  3,  0,131,  7, 63,192,  0,  0,  0,  0,  0,  0,  0,128,128,  0,  0,128,224,255,241,238,239,255,254,159, 15, 47,159,255,255,255,255,191,128,  4,  6,  3,  3,  3,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  7, 15, 63,127,255,255,255,254,254,254, 28, 59,255,254,133, 13, 31, 31, 63,123,241,224,245,123,127, 63, 63, 31, 31, 15, 31, 31, 63,126,248,224,128,  0,  0,  7, 15, 63,127,255,255,255,254,254,254, 28, 59,255,254,133, 13, 31, 31, 63,123,241,224,245,123,127, 63, 63, 31, 31, 15, 31, 31, 63,126,248,224,128,  0,  0,  7, 15, 63,127,255,255,255,254,254,254, 28, 59,255,254,133, 13, 31, 31, 63,123,241,224,245,123,127, 63, 63, 31, 31, 15, 31, 31, 63,126,248,224,128,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,192,224, 49,  3,  3,  7,  7,  6, 12,216,153, 39, 39, 34, 34, 35, 97,193,128,192, 96, 48, 96,193,227,250,124, 63, 30, 60,120,240,225,195,134,  0,  0,  0,128,192,224, 49,  3,  3,  7,  7,  6, 12,216,153, 39, 39, 34, 34, 35, 97,193,128,192, 96, 48, 96,193,227,250,124, 63, 30, 60,120,240,225,195,134,  0,  0,  0,128,192,224, 49,  3,  3,  7,  7,  6, 12,216,153, 39, 39, 34, 34, 35, 97,193,128,192, 96, 48, 96,193,227,250,124, 63, 30, 60,120,240,225,195,134,  0,  0,
    };
    oled_write_raw_P(raw_logo, sizeof(raw_logo));

    // oled_write_P(raw_logo, false);
}

static void print_status_narrow(void) {
    oled_write_P(PSTR("Sofle"), false);
    oled_write_P(PSTR("\n\n\n"), false);
    // Print current mode
    switch (get_highest_layer(layer_state)) {
        case 0:
            oled_write_ln_P(PSTR("Qwrt"), false);
            break;
        default:
            oled_write_P(PSTR("Mod\n"), false);
            break;
    }
    oled_write_P(PSTR("\n\n"), false);
    // Print current layer
    oled_write_ln_P(PSTR("LAYER"), false);
    switch (get_highest_layer(layer_state)) {
        case 0:
            oled_write_P(PSTR("Base\n"), false);
            break;
        case 1:
            oled_write_P(PSTR("Upper"), false);
            break;
        case 2:
            oled_write_P(PSTR("Lower"), false);
            break;
        case 3:
            oled_write_P(PSTR("Extra"), false);
        default:
            oled_write_ln_P(PSTR("Undef"), false);
    }
    oled_write_P(PSTR("\n\n"), false);
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_270;
    }
    return rotation;
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        print_status_narrow();
    } else {
        render_logo();
    }
    return false;
}

#endif
