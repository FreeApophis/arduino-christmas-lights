#pragma once

#include "animation/Animation.h"
#include "manipulation/BrightnessManipulation.h"

#include "framework.h"

// Rapid walking by the different colors
class WalkSeven : public Animation {
  public:
    WalkSeven(AbstractLedStrip* strip);

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
