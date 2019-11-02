#pragma once

#include "animation/Animation.h"
#include "framework.h"

// Fast collide of two colors
class CollideOne : public Animation {
  public:
    CollideOne(AbstractLedStrip* strip);

    void Init() override;
    void Show() override;

  private:
    uint32_t _leftColor;
    uint32_t _rightColor;
    int _left;
    int _right;
    bool _isBooom;
};
