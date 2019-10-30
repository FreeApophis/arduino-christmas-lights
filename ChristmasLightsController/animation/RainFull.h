#pragma once

#include "Animation.h"
#include "../BrightnessManipulation.h"
#include "../framework.h"

// show the rainbow colors on the entire strip
class RainFull : public BrightnessManipulation, public Animation {
  public:
    RainFull(AbstractLedStrip* strip, byte duration);

    virtual void Init()
    {
        index = random(256);
        rdy = false;
    }
    virtual void Show();

  private:
    byte index;
    bool rdy;
};
