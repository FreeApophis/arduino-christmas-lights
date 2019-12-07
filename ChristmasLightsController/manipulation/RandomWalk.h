#pragma once

#include "framework.h"

// This function applies a random walk to val by increasing or
// decreasing it by changeAmount or by leaving it unchanged.
// val is a pointer to the byte to be randomly changed.
// The new value of val will always be within [0, maxVal].
// A walk direction of 0 decreases val and a walk direction of 1
// increases val.  The directions argument specifies the number of
// possible walk directions to choose from, so when directions is 1, val
// will always decrease; when directions is 2, val will have a 50% chance
// of increasing and a 50% chance of decreasing; when directions is 3,
// val has an equal chance of increasing, decreasing, or staying the same.
auto RandomWalk(uint8_t val, uint8_t maxVal, uint8_t changeAmount, uint8_t directions) -> uint8_t;
