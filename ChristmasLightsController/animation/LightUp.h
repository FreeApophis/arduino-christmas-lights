#pragma once

#include "Animation.h"
#include "../BrightnessManipulation.h"
#include "../framework.h"

//---------------------------------------------- Light up with the random color than fade out -----------------------------
class LightUp : public BrightnessManipulation, public Animation {
  public:
    LightUp(AbstractLedStrip* strip, byte duration);

    virtual void init()
    {
        sp = 1;
        inc = sp;
        newColor();
    }
    virtual void show();

  private:
    void newColor();
    byte sp;
    char inc;
};
