#pragma once

#include "animation/Animation.h"
#include "manipulation/BrightnessManipulation.h"

#include "framework.h"

// Slow single wave moving in random direction
class LightHouse final : public Animation {
  public:
    explicit LightHouse(AbstractLedStrip* strip);

    auto Init() -> void override;
    auto Show() -> void override;

  private:
    BrightnessManipulation _brightnessManipulation;
    uint32_t _dots[5]{};
    int _position;
    byte _step;
    char _increment;
    byte _speed;
    byte _delay;
};
