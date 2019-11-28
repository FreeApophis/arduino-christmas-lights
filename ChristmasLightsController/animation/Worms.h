#pragma once

#include "animation/Animation.h"
#include "manipulation/BrightnessManipulation.h"
#include "framework.h"
#include "Worm.h"

// Several worms are moving randomly
class Worms : public Animation {
  public:
    Worms(AbstractLedStrip* strip);

    void Init() override;
    void Show() override;

  private:
    void Add();
    void Die(byte index);

    BrightnessManipulation _brightnessManipulation;
    Worm _worms[5]{};
    byte _active{};
};
