#pragma once

#include "animation/Animation.h"
#include "manipulation/BrightnessManipulation.h"

#include "framework.h"

// Slow shining and flash by the different colors
class ShineFlash final : public Animation {
  public:
    explicit ShineFlash(AbstractLedStrip* strip);

    auto Init() -> void override;
    auto Show() -> void override;

  private:
    auto StartNewColor() -> void;

    BrightnessManipulation _brightnessManipulation;
    byte _wheelIndex;
    byte _mode;
    bool _isFlash;
    int _remaining;
    int _index;
    char _wait;
};
