#pragma once

#include "Animation.h"
#include "../BrightnessManipulation.h"
#include "../framework.h"

//---------------------------------------------- Light up with the random color than fade out -----------------------------
class LightUp : public BrightnessManipulation, public Animation {
  public:
    LightUp(AbstractLedStrip* strip, byte duration);

    virtual void Init()
    {
        sp = 1;
        inc = sp;
        newColor();
    }
    virtual void Show();

  private:
    void newColor();
    byte sp;
    char inc;
};
