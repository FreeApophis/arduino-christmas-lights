#pragma once

#include "Animation.h"
#include "../BrightnessManipulation.h"
#include "../framework.h"

// show the rainbow (from neopixel example)
class Rainbow : public BrightnessManipulation, public Animation {
  public:
    Rainbow(AbstractLedStrip* strip, byte duration);

    virtual void init()
    {
        index = 0;
        rdy = false;
    }
    virtual void show();

  private:
    byte index;
    bool rdy;
};