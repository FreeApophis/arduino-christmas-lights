#pragma once

#include "animation/Animation.h"
#include "manipulation/BrightnessManipulation.h"

#include "framework.h"

// Fill the strip by the color in random order
class RandomFill final : public Animation {
  public:
    explicit RandomFill(AbstractLedStrip* strip);

    auto Init() -> void override;
    auto Show() -> void override;

  private:
    auto NewDot(bool clear) -> void;

    BrightnessManipulation _brightnessManipulation;
    byte _wheelIndex;
    int _remaining;
    uint16_t _position;
    bool _isClear;
};
