#pragma once

#include "Animation.h"
#include "../BrightnessManipulation.h"
#include "../framework.h"

// Slow shining by the different colors
class ShineSeven : public BrightnessManipulation, public Animation {
  public:
    ShineSeven(AbstractLedStrip* strip, byte duration);
    virtual void Init();
    virtual void Show();

  private:
    void startNewColor();
    byte curs;
    byte w;
    byte base;
};
