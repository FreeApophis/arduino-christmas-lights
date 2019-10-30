#pragma once

#include "Animation.h"
#include "../BrightnessManipulation.h"
#include "../framework.h"
#include "Worm.h"

// Several worms are moving randomly
class Worms : public BrightnessManipulation, public Animation {
  public:
    Worms(AbstractLedStrip* strip);

    void Init() override;
    void Show() override;

  private:
    void Add();
    void Die(byte index);

    Worm _worms[5]{};
    byte _active{};
};
