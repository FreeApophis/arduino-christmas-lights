#pragma once

#include "AbstractLedStrip.h"
#include "framework.h"

// Blend manipulations
class BlendManipulations {
  public:
    BlendManipulations(AbstractLedStrip* strip);
    uint32_t add(uint32_t color1, uint32_t color2);
    uint32_t sub(uint32_t color1, uint32_t color2);
    void blendPixel(uint16_t p);
private:
    AbstractLedStrip*  _blendStrip{};
};
