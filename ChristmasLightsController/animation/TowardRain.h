#pragma once

#include "Animation.h"
#include "../framework.h"

// Rainbow colors toward each other
class TowardRain : public Animation {
  public:
    TowardRain(AbstractLedStrip* strip, byte duration);
    virtual void init() { w = random(256); }
    virtual void show();

  private:
    byte w;
};
