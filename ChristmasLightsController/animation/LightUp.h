#pragma once

#include "animation/Animation.h"
#include "manipulation/BrightnessManipulation.h"

#include "framework.h"

// Light up with the random color than fade out
class LightUp final : public Animation {
  public:
    explicit LightUp(AbstractLedStrip* strip);

    auto Init() -> void override;
    auto Show() -> void override;

  private:
    auto NewColor() -> void;

    BrightnessManipulation _brightnessManipulation;
    byte _speed;
    char _increment;
};
