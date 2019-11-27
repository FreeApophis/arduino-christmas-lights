#pragma once

#include "Animation.h"
#include "framework.h"

// Lights run from the center
class CenterRun final : public Animation {
  public:
    CenterRun(AbstractLedStrip* strip, byte duration);

    void Init() override;
    void Show() override;

  private:
    uint32_t _color;
    int _left;
    int _middle;
    int _right;
};
