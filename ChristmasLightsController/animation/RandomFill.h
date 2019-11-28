#pragma once

#include "manipulation/BrightnessManipulation.h"
#include "framework.h"
#include "animation/Animation.h"

// Fill the strip by the color in random order
class RandomFill : public Animation {
  public:
    RandomFill(AbstractLedStrip* strip, byte duration);

    void Init() override;
    void Show() override;

  private:
    void newDot(bool clr);
    BrightnessManipulation _brightnessManipulation;
    byte w{};
    int remain{};
    uint16_t pos{};
    bool clr{};
};
