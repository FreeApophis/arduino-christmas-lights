#pragma once
#include "animation/Animation.h"
#include "manipulation/BrightnessManipulation.h"
#include "manipulation/Crawl.h"

// show the color Wave using rainbowCycle

class ColorWave : public Animation {
  public:
    ColorWave(AbstractLedStrip* strip);

    void Init() override;
    void Show() override;

  private:
    BrightnessManipulation _brightnessManipulation;
    Crawl _crawl;
    byte _index;
    bool _isReady;
};