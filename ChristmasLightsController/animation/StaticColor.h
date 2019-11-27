#pragma once

#include "Animation.h"

// show the color Wave using rainbowCycle

class StaticColor : public Animation {
  public:
    StaticColor(AbstractLedStrip* strip, byte duration);

    void Init() override;
    void Show() override;

  private:
    uint32_t _color;
};
