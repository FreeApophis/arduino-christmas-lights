#pragma once

#include "Animation.h"
#include "../BrightnessManipulation.h"
#include "../framework.h"

// Rapid flashing by the differenc colors
class FlashSeven : public BrightnessManipulation, public Animation {
  public:
    FlashSeven(AbstractLedStrip* strip, byte duration);
    virtual void init();
    virtual void show();

  private:
    char curs;
    byte w;
    bool fwd;
    int ch_dir;
    byte period;
};
