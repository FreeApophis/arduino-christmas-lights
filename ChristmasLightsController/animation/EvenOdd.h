#pragma once

#include "Animation.h"
#include "../framework.h"

//---------------------------------------------- Even and odd position leds are moving towards each other ---------------
class EvenOdd : public Animation {
  public:
    EvenOdd(AbstractLedStrip* strip, byte duration) :
        Animation(strip, duration, 10, 20)
    {
    }
    virtual void init();
    virtual void show();

  private:
    uint32_t cl, cr;
    int l, r;
};
