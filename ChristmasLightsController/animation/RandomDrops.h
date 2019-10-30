#pragma once

#include "Animation.h"
#include "../BrightnessManipulation.h"
#include "Drop.h"

// Random dropped color dot fading out from epicenter
class RandomDrops : public BrightnessManipulation, public Animation {
  public:
    RandomDrops(AbstractLedStrip* strip);

    virtual void Init();
    virtual void Show();

  private:
    void add();

    struct Drop dr[16];
    char num;
};
