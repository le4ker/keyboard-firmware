// Copyright 2023 Panos Sakkos <panos.sakkos@gmail.com> @le4ker
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

#pragma once

#define MASTER_LEFT
#define SPLIT_LAYER_STATE_ENABLE // Share layer state with right half
#define OLED_FADE_OUT
#define OLED_FADE_OUT_INTERVAL 15 // Slowest fade out
#define OLED_TIMEOUT 120000       // OLED timeout (ms)
#define DEBOUNCE 6                // Debounce time (ms)
#define FORCE_NKRO                // N-Key Rollover on by default

// Disabled features to improve the matrix scan rate
// and save firmware space.
#define NO_ACTION_TAPPING
#define NO_ACTION_ONESHOT

#define OLED_UPDATE_INTERVAL 300 // Lower interval to improve matrix scan rate
#define LAYER_STATE_8BIT         // 8 bit layer state to save space

#define USB_POLLING_INTERVAL_MS 1 // Higher USB polling frequency

// Print matrix scan rate when in debug mode.
#if defined(CONSOLE_ENABLE)
#    define DEBUG_MATRIX_SCAN_RATE
#endif
