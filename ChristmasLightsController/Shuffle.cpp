#include "Shuffle.h"

Shuffle::Shuffle(byte numberOfAnimations)
{
    for (byte i = 0; i < numberOfAnimations; ++i)
        index[i] = i;
    _current = num_anim = numberOfAnimations;
}

byte Shuffle::next()
{
    if (_current >= num_anim)
        randomize();
    return index[_current++];
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
    _current = 0;
}