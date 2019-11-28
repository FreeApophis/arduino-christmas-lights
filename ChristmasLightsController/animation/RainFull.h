#pragma once

#include "animation/Animation.h"
#include "manipulation/BrightnessManipulation.h"

#include "framework.h"

// show the rainbow colors on the entire strip
class RainFull : public Animation {
  public:
    RainFull(AbstractLedStrip* strip);

    void Init() override;
    void Show() override;

  private:
    BrightnessManipulation _brightnessManipulation;
    byte index{};
    bool rdy{};
};
