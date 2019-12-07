#pragma once

#include "animation/Animation.h"
#include "manipulation/BrightnessManipulation.h"

#include "framework.h"

// Show single wave moving in random direction
class SingleWave final : public Animation {
  public:
    explicit SingleWave(AbstractLedStrip* strip);

    auto Init() -> void override;
    auto Show() -> void override;

  private:
    BrightnessManipulation _brightnessManipulation;
    uint32_t _dots[5];
    int _position;
    byte _stop;
    byte _remain;
    char _increment;
    byte _mode;
};