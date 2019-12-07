#pragma once

#include "animation/Animation.h"

#include "framework.h"

// Random colors from left and right move to the center
class WalkToCenter final : public Animation {
  public:
    explicit WalkToCenter(AbstractLedStrip* strip);

    auto Init() -> void override;
    auto Show() -> void override;

  private:
    auto NewColors() -> void;
    uint32_t _colorLeft;
    uint32_t _colorRight;
    int _left;
    int _right;
    int _leftMiddle;
    int _rightMiddle;
    bool _clear;
};
