#pragma once

#include "BrightnessManipulation.h"
#include "animation/Animation.h"

#include "framework.h"

// Rapid walking by the different colors
class WalkSeven : public BrightnessManipulation, public Animation {
  public:
    WalkSeven(AbstractLedStrip* strip, byte duration);

    void Init() override;
    void Show() override;

  private:
    char curs{};
    byte w{};
    bool fwd{};
    int ch_dir{};
    byte period{};
};
