#pragma once

#include "Animation.h"
#include "../BrightnessManipulation.h"
#include "../framework.h"

// Random sparks
class Sparks : public BrightnessManipulation, public Animation {
  public:
    Sparks(AbstractLedStrip* strip, byte duration);

    void Init() override;

    void Show() override;

  private:
    uint16_t _positions[8]{};
};