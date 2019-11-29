#pragma once

#include "animation/Animation.h"
#include "manipulation/BrightnessManipulation.h"

#include "framework.h"

// Slow shining and flash by the different colors
class ShineFlash : public Animation {
  public:
    ShineFlash(AbstractLedStrip* strip);

    void Init() override;
    void Show() override;

  private:
    BrightnessManipulation _brightnessManipulation;
    void startNewColor();
    byte w;
    byte mode;
    bool flash;
    int remain;
    int indx;
    char wait;
};
