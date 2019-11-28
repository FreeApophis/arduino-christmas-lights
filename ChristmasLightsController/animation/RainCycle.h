#pragma once

#include "animation/Animation.h"
#include "manipulation/BrightnessManipulation.h"

#include "framework.h"

class RainCycle : public Animation {
  public:
    RainCycle(AbstractLedStrip* strip, byte duration);

    void Init() override;
    void Show() override;

  private:
    BrightnessManipulation _brightnessManipulation;
    byte index;
    bool rdy;
};
