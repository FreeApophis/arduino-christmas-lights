#pragma once

#include "animation/Animation.h"
#include "manipulation/BrightnessManipulation.h"

#include "framework.h"

// Random sparks
class Sparks : public Animation {
  public:
    Sparks(AbstractLedStrip* strip);

    void Init() override;

    void Show() override;

  private:
    BrightnessManipulation _brightnessManipulation;
    uint16_t _positions[8];
};