#pragma once

#include "animation/Animation.h"

#include "framework.h"

// Even and odd position leds are moving towards each other
class EvenOdd : public Animation {
  public:
    EvenOdd(AbstractLedStrip* strip);

    void Init() override;
    void Show() override;

  private:
    uint32_t cl;
    uint32_t cr;
    int l;
    int r;
};
