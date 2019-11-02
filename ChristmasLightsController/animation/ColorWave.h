#pragma once
#include "BrightnessManipulation.h"
#include "Crawl.h"
#include "animation/Animation.h"

// show the color Wave using rainbowCycle

class ColorWave : public BrightnessManipulation, public Animation {
  public:
    ColorWave(AbstractLedStrip* strip, byte duration);

    void Init() override;
    void Show() override;

  private:
    Crawl _crawl;
    byte _index;
    bool _isReady;
};