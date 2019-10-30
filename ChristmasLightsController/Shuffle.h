#pragma once

#include "framework.h"

class Shuffle {
  public:
    Shuffle(byte a_size)
    {
        for (byte i = 0; i < a_size; ++i)
            index[i] = i;
        curr = num_anim = a_size;
    }
    byte next();

  private:
    void randomize();
    byte index[34]; // The maximum number of animations
    byte num_anim;  // The active animation number
    byte curr;
};
