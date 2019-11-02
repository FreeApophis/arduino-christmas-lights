#pragma once

#include "BrightnessManipulation.h"
#include "framework.h"
#include "animation/Animation.h"

// Fill the strip by the color in random order
class RandomFill : public BrightnessManipulation, public Animation {
  public:
    RandomFill(AbstractLedStrip* strip, byte duration);

    void Init() override;
    void Show() override;

  private:
    void newDot(bool clr);
    byte w{};
    int remain{};
    uint16_t pos{};
    bool clr{};
};
