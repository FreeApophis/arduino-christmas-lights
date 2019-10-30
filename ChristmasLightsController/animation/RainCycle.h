#pragma once

#include "Animation.h"
#include "../BrightnessManipulation.h"
#include "../framework.h"

class RainCycle : public BrightnessManipulation, public Animation {
  public:
    RainCycle(AbstractLedStrip* strip, byte duration);

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
