#pragma once

#include "Animation.h"
#include "../BrightnessManipulation.h"
#include "../framework.h"

// Show single wave moving in random direction
class SingleWave : public BrightnessManipulation, public Animation {
  public:
    SingleWave(AbstractLedStrip* strip);
    virtual void Init();
    virtual void Show();

  private:
    uint32_t dot[5];
    int pos;
    byte stp;
    byte remain;
    char incr;
    byte mode;
    byte w;
};