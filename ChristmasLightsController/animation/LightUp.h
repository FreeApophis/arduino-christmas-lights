#pragma once

#include "animation/Animation.h"
#include "manipulation/BrightnessManipulation.h"

#include "framework.h"

// Light up with the random color than fade out
class LightUp : public Animation {
  public:
    LightUp(AbstractLedStrip* strip, byte duration);

    void Init() override;
    void Show() override;

  private:
    BrightnessManipulation _brightnessManipulation;
    void NewColor();

    byte sp;
    char inc;
};
