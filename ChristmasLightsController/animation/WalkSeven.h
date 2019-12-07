#pragma once

#include "animation/Animation.h"
#include "manipulation/BrightnessManipulation.h"

#include "framework.h"

// Rapid walking by the different colors
class WalkSeven final : public Animation {
  public:
    explicit WalkSeven(AbstractLedStrip* strip);

    auto Init() -> void override;
    auto Show() -> void override;

  private:
    BrightnessManipulation _brightnessManipulation;
    char _current;
    byte _wheelIndex;
    bool _isForward;
    int _changeDirection;
    byte _period;
};
