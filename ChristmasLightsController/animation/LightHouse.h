#pragma once

#include "animation/Animation.h"
#include "manipulation/BrightnessManipulation.h"

#include "framework.h"

// Slow single wave moving in random direction
class LightHouse : public Animation {
  public:
    LightHouse(AbstractLedStrip* strip);

    void Init() override;
    void Show() override;

  private:
    BrightnessManipulation _brightnessManipulation;
    uint32_t dot[5];
    int pos;
    byte stp;
    char incr;
    byte sp;
    byte dlay;
};
