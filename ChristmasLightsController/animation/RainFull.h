#pragma once

#include "animation/Animation.h"
#include "manipulation/BrightnessManipulation.h"

#include "framework.h"

// show the rainbow colors on the entire strip
class RainFull final : public Animation {
  public:
    explicit RainFull(AbstractLedStrip* strip);

    auto Init() -> void override;
    auto Show() -> void override;

  private:
    BrightnessManipulation _brightnessManipulation;
    byte _index;
    bool _isReady;
};
