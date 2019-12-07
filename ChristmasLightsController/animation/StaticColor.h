#pragma once

#include "Animation.h"

// show the color Wave using rainbowCycle

class StaticColor final : public Animation {
  public:
    StaticColor(AbstractLedStrip* strip, int32_t color, uint16_t animationId);

    auto Init() -> void override;
    auto Show() -> void override;

  private:
    uint32_t _color;
};
