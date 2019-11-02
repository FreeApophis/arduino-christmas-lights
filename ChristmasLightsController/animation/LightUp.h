#pragma once

#include "animation/Animation.h"
#include "BrightnessManipulation.h"
#include "framework.h"

// Light up with the random color than fade out
class LightUp : public BrightnessManipulation, public Animation {
  public:
    LightUp(AbstractLedStrip* strip, byte duration);

    void Init() override;
    void Show() override;

  private:
    void NewColor();

    byte sp;
    char inc;
};
