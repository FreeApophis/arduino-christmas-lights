#pragma once

#include "animation/Animation.h"
#include "manipulation/BrightnessManipulation.h"

#include "framework.h"

class RainCycle : public Animation {
  public:
    RainCycle(AbstractLedStrip* strip);

    void Init() override;
    void Show() override;

  private:
    uint32_t ColorWheelFromIndex(uint16_t i) const;
    void Brighten();
    BrightnessManipulation _brightnessManipulation;
    byte _index;
    bool _brightenPhase;
};
