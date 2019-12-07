#pragma once

#include "animation/Animation.h"

#include "framework.h"

// Even and odd position leds are moving towards each other
class EvenOdd final : public Animation {
  public:
    explicit EvenOdd(AbstractLedStrip* strip);

    auto Init() -> void override;
    auto Show() -> void override;

  private:
    uint32_t _leftColor;
    uint32_t _rightColor;
    int _left;
    int _right;
};
