#pragma once

#include "animation/Animation.h"

#include "framework.h"

// Fast collide of two colors
class CollideOne final : public Animation {
  public:
    explicit CollideOne(AbstractLedStrip* strip);

    auto Init() -> void override;
    auto Show() -> void override;

  private:
    uint32_t _leftColor;
    uint32_t _rightColor;
    int _left;
    int _right;
    bool _isBooom;
};
