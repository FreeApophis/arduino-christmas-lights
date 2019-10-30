#pragma once

#include "Animation.h"
#include "../BrightnessManipulation.h"
#include "../ColorSuperposition.h"
#include "Drop.h"

// Random dropped color dot fading out from epicenter
class RandomDrops : public BrightnessManipulation, public ColorSuperposition, public Animation {
  public:
    RandomDrops(AbstractLedStrip* strip);

    virtual void init();
    virtual void show();

  private:
    void add();

    struct Drop dr[16];
    char num;
};
