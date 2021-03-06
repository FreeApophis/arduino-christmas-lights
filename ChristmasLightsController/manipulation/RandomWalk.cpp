#include "RandomWalk.h"

auto RandomWalk(const uint8_t val, const uint8_t maxVal, const uint8_t changeAmount, const uint8_t directions) -> uint8_t
{
    const unsigned char direction = random(directions) == 0; // direction of random walk
    if (direction == 0) {
        // decrease val by changeAmount down to a min of 0
        if (val >= changeAmount) {
            return val - changeAmount;
        } else {
            return 0;
        }
    }
    if (direction == 1) {
        // increase val by changeAmount up to a max of maxVal
        if (val <= maxVal - changeAmount) {
            return val + changeAmount;
        } else {
            return maxVal;
        }
    }

    return val;
}
