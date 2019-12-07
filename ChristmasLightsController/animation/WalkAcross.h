#pragma once

#include "animation/Animation.h"

#include "framework.h"

// Random colors from left and right move to the other end
class WalkAcross final : public Animation {
  public:
    explicit WalkAcross(AbstractLedStrip* strip);

    auto Init() -> void override;
    auto Show() -> void override;

  private:
    auto NewColors() -> void;

    uint32_t _leftColor;
    uint32_t _rightColor;
    int _left;
    int _right;
    int _borderLeft;
    int _borderRight;
};
