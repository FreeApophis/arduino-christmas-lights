#pragma once

#include "animation/Animation.h"

#include "framework.h"

// Slow merging of two colors
class MergeOne final : public Animation {
  public:
    explicit MergeOne(AbstractLedStrip* strip);

    auto Init() -> void override;
    auto Show() -> void override;

  private:
    uint32_t _leftColor;
    uint32_t _rightColor;
    int _left;
    int _right;
};
