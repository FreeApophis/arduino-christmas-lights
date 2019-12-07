#pragma once

#include "AbstractLedStrip.h"

#include "framework.h"

// Brightness manipulation
class BrightnessManipulation final {
  public:
    BrightnessManipulation(AbstractLedStrip* strip);

    auto SetColor(uint32_t color) -> void;
    auto Change(uint16_t index, int value) -> bool;
    auto ChangeAll(int value) -> bool;

  protected:
    byte _color[3];

  private:
    AbstractLedStrip* _brightStrip;
};