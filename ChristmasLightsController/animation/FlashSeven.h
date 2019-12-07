#pragma once

#include "animation/Animation.h"
#include "manipulation/BrightnessManipulation.h"

#include "framework.h"

// Rapid flashing by the differenc colors
class FlashSeven final : public Animation {
  public:
    explicit FlashSeven(AbstractLedStrip* strip);

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
