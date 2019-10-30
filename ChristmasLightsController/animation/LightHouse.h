#pragma once

#include "Animation.h"
#include "../BrightnessManipulation.h"
#include "../framework.h"

// Slow single wave moving in random direction
class LightHouse : public BrightnessManipulation, public Animation {
  public:
    LightHouse(AbstractLedStrip* strip);
    virtual void init();
    virtual void show();

  private:
    uint32_t dot[5];
    int pos;
    byte stp;
    char incr;
    byte sp;
    byte dlay;
};
