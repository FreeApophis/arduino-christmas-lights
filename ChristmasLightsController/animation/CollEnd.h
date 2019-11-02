#pragma once

#include "animation/Animation.h"

#include "framework.h"

// Random colors from left and right move to the other end
class CollEnd : public Animation {
  public:
    CollEnd(AbstractLedStrip* strip, byte duration);

    void Init() override;
    void Show() override;

  private:
    void newColors();
    uint32_t _leftColor;
    uint32_t _rightColor;
    int _left;
    int _right;
    int _borderLeft;
    int _border_right;
};
