#pragma once

#include "animation/Animation.h"
#include "BrightnessManipulation.h"
#include "framework.h"

// Rapid flashing by the differenc colors
class FlashSeven : public BrightnessManipulation, public Animation {
  public:
    FlashSeven(AbstractLedStrip* strip, byte duration);

    void Init() override;
    void Show() override;

  private:
    char curs;
    byte w;
    bool fwd;
    int ch_dir;
    byte period;
};
