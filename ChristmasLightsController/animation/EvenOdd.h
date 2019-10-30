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
    virtual void Init();
    virtual void Show();

  private:
    uint32_t cl, cr;
    int l, r;
};
