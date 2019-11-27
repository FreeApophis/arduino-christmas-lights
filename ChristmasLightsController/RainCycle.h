#pragma once

#include "Animation.h"
#include "BrightnessManipulation.h"
#include "framework.h"

class RainCycle : public BrightnessManipulation, public Animation {
  public:
    RainCycle(AbstractLedStrip* strip, byte duration);

    void Init() override;
    void Show() override;

  private:
    byte index;
    bool rdy;
};
