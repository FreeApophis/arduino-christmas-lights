#pragma once

#include "Animation.h"
#include "../BrightnessManipulation.h"
#include "../framework.h"

// Random sparks fade out
class RandomFade : public BrightnessManipulation, public Animation {
  public:
    RandomFade(AbstractLedStrip* strip, byte duration);
    virtual void init() {}
    virtual void show();
};