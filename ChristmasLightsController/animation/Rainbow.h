#pragma once

#include "animation/Animation.h"
#include "manipulation/BrightnessManipulation.h"

#include "framework.h"

// show the rainbow (from neopixel example)
class Rainbow final : public Animation {
  public:
    explicit Rainbow(AbstractLedStrip* strip);

    auto Init() -> void override;
    auto Show() -> void override;

  private:
    BrightnessManipulation _brightnessManipulation;
    byte _index;
    bool _isReady;
};