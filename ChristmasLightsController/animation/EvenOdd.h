#pragma once

#include "Animation.h"
#include "../framework.h"

//---------------------------------------------- Even and odd position leds are moving towards each other ---------------
class EvenOdd : public Animation {
  public:
    EvenOdd(AbstractLedStrip* strip, byte duration);

    void Init() override;
    void Show() override;

  private:
    uint32_t cl, cr;
    int l, r;
};
