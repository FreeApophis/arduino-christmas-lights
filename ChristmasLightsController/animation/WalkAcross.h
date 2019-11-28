#pragma once

#include "animation/Animation.h"

#include "framework.h"

// Random colors from left and right move to the other end
class WalkAcross : public Animation {
  public:
    WalkAcross(AbstractLedStrip* strip);

    void Init() override;
    void Show() override;

  private:
    void newColors();
    uint32_t _leftColor;
    uint32_t _rightColor;
    int _left;
    int _right;
    int _borderLeft;
    int _borderRight;
};
