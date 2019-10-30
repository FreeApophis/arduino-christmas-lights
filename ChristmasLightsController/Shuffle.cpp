#include "Shuffle.h"

byte Shuffle::next()
{
    if (curr >= num_anim)
        randomize();
    return index[curr++];
}

void Shuffle::randomize()
{
    for (byte i = 0; i < num_anim * 2; ++i) {
        byte p1 = random(num_anim);
        byte p2 = random(num_anim);
        if (p1 != p2) {
            byte t = index[p2];
            index[p2] = index[p1];
            index[p1] = t;
        }
    }
    curr = 0;
}