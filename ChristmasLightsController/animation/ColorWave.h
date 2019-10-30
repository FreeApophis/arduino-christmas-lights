#pragma once
#include "../BrightnessManipulation.h"
#include "../Crawl.h"
#include "Animation.h"

// show the color Wave using rainbowCycle

class ColorWave : public Crawl, public BrightnessManipulation, public Animation {
  public:
    ColorWave(AbstractLedStrip* strip, byte duration);
    virtual void Init();
    virtual void Show();

  private:
    byte index;
    bool rdy;
};