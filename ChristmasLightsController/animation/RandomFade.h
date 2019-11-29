#pragma once

#include "animation/Animation.h"
#include "manipulation/BrightnessManipulation.h"

#include "framework.h"

// Random sparks fade out
class RandomFade : public Animation {
  public:
    RandomFade(AbstractLedStrip* strip);

    void Init() override ;
    void Show() override;

  private:
    BrightnessManipulation _brightnessManipulation;
};