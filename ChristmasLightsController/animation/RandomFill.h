#pragma once

#include "../BrightnessManipulation.h"
#include "../framework.h"
#include "Animation.h"

// Fill the strip by the color in random order
class RandomFill : public BrightnessManipulation, public Animation {
  public:
    RandomFill(AbstractLedStrip* strip, byte duration);
    virtual void Init();
    virtual void Show();

  private:
    void newDot(bool clr);
    byte w;
    int remain;
    uint16_t pos;
    bool clr;
};
