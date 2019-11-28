#pragma once

#include "animation/Animation.h"
#include "manipulation/BrightnessManipulation.h"

#include "framework.h"

// show the rainbow (from neopixel example)
class Rainbow : public Animation {
  public:
    Rainbow(AbstractLedStrip* strip);

    void Init() override;
    void Show() override;

  private:
    BrightnessManipulation _brightnessManipulation;
    byte index;
    bool rdy;
};