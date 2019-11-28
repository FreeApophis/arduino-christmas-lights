#pragma once

#include "animation/Animation.h"
#include "manipulation/BrightnessManipulation.h"

#include "framework.h"

// Rapid flashing by the differenc colors
class FlashSeven : public Animation {
  public:
    FlashSeven(AbstractLedStrip* strip, byte duration);

    void Init() override;
    void Show() override;

  private:
    BrightnessManipulation _brightnessManipulation;
    char curs;
    byte w;
    bool fwd;
    int ch_dir;
    byte period;
};
