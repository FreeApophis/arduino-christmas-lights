#pragma once

#include "Animation.h"
#include "../BrightnessManipulation.h"
#include "../framework.h"

// Random sparks
class Sparks : public BrightnessManipulation, public Animation {
  public:
    Sparks(AbstractLedStrip* strip, byte duration);

    virtual void Init()
    {
        for (byte i = 0; i < 8; ++i) {
            pos[i] = 0;
        }
    }
    virtual void Show();

  private:
    uint16_t pos[8];
};