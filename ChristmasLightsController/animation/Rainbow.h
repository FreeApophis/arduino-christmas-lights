#pragma once

#include "animation/Animation.h"
#include "BrightnessManipulation.h"
#include "framework.h"

// show the rainbow (from neopixel example)
class Rainbow : public BrightnessManipulation, public Animation {
  public:
    Rainbow(AbstractLedStrip* strip, byte duration);

    void Init() override;
    void Show() override;

  private:
    byte index;
    bool rdy;
};