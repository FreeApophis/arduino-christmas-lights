#pragma once

#include "Drop.h"
#include "animation/Animation.h"
#include "manipulation/BrightnessManipulation.h"

// Random dropped color dot fading out from epicenter
class RandomDrops : public Animation {
  public:
    RandomDrops(AbstractLedStrip* strip);

    void Init() override;
    void Show() override;

  private:
    void add();
    BrightnessManipulation _brightnessManipulation;
    Drop dr[16];
    char num;
};
