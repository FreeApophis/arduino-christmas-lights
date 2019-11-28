#pragma once

#include "animation/Animation.h"
#include "manipulation/BrightnessManipulation.h"

#include "framework.h"

// Show single wave moving in random direction
class SingleWave : public Animation {
  public:
    SingleWave(AbstractLedStrip* strip);

    void Init() override;
    void Show() override;

  private:
    BrightnessManipulation _brightnessManipulation;
    uint32_t dot[5]{};
    int pos{};
    byte stp{};
    byte remain{};
    char incr{};
    byte mode{};
    byte w{};
};