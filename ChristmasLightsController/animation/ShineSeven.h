#pragma once

#include "animation/Animation.h"
#include "manipulation/BrightnessManipulation.h"

#include "framework.h"

// Slow shining by the different colors
class ShineSeven : public Animation {
  public:
    ShineSeven(AbstractLedStrip* strip);

    void Init() override;
    void Show() override;

  private:
    BrightnessManipulation _brightnessManipulation;
    void startNewColor();
    byte curs;
    byte w;
    byte base;
};
