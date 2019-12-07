#pragma once
#include "animation/Animation.h"
#include "manipulation/BrightnessManipulation.h"
#include "manipulation/Crawl.h"

// show the color Wave using rainbowCycle

class ColorWave final : public Animation {
  public:
    explicit ColorWave(AbstractLedStrip* strip);

    auto Init() -> void override;
    auto Show() -> void override;

  private:
    BrightnessManipulation _brightnessManipulation;
    Crawl _crawl;
    byte _index;
    bool _isReady;
};