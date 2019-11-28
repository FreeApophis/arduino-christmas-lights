#pragma once
#include "manipulation/BrightnessManipulation.h"
#include "manipulation/Crawl.h"
#include "animation/Animation.h"

// show the color Wave using rainbowCycle

class ColorWave : public Animation {
  public:
    ColorWave(AbstractLedStrip* strip, byte duration);

    void Init() override;
    void Show() override;

  private:
    BrightnessManipulation _brightnessManipulation;
    Crawl _crawl;
    byte _index;
    bool _isReady;
};