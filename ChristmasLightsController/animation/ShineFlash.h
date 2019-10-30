#pragma once

#include "Animation.h"
#include "../BrightnessManipulation.h"
#include "../framework.h"

// Slow shining and flash by the different colors
class ShineFlash : public BrightnessManipulation, public Animation {
  public:
    ShineFlash(AbstractLedStrip* strip, byte duration);

    void Init() override;
    void Show() override;

  private:
    void startNewColor();
    byte w{};
    byte mode{};
    bool flash{};
    int remain{};
    int indx{};
    char wait{};
};
