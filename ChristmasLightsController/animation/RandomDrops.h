#pragma once

#include "animation/Animation.h"
#include "BrightnessManipulation.h"
#include "Drop.h"

// Random dropped color dot fading out from epicenter
class RandomDrops : public BrightnessManipulation, public Animation {
  public:
    RandomDrops(AbstractLedStrip* strip);

    void Init() override;
    void Show() override;

  private:
    void add();

    struct Drop dr[16]{};
    char num{};
};
