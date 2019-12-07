#pragma once

#include "animation/Animation.h"
#include "manipulation/BrightnessManipulation.h"

#include "framework.h"

// Slow shining by the different colors
class ShineSeven final : public Animation {
  public:
    explicit ShineSeven(AbstractLedStrip* strip);

    auto Init() -> void override;
    auto Show() -> void override;

  private:
    auto StartNewColor() -> void;

    BrightnessManipulation _brightnessManipulation;
    byte _current;
    byte _wheelIndex;
    byte _base;
};
