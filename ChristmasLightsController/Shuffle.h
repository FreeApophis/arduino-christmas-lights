#pragma once

#include "framework.h"

class Shuffle {
  public:
    Shuffle(byte numberOfAnimations);
    byte next();

  private:
    void randomize();
    byte index[34]{}; // The maximum number of animations
    byte num_anim;  // The active animation number
    byte _current;
};
