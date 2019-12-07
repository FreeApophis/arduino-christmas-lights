#pragma once

#include "animation/Animation.h"
#include "manipulation/BrightnessManipulation.h"

#include "framework.h"

class RainCycle final : public Animation {
  public:
    explicit RainCycle(AbstractLedStrip* strip);

    auto Init() -> void override;
    auto Show() -> void override;

  private:
    auto ColorWheelFromIndex(uint16_t index) const -> uint32_t;
    auto Brighten() -> void;

    BrightnessManipulation _brightnessManipulation;
    byte _index;
    bool _brightenPhase;
};
