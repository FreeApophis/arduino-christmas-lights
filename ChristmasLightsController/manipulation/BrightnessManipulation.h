#pragma once

#include "AbstractLedStrip.h"

#include "framework.h"

// Brightness manipulation
class BrightnessManipulation final {
  public:
    BrightnessManipulation(AbstractLedStrip* strip);
    void setColor(uint32_t c);
    bool change(uint16_t index, int val);
    bool changeAll(int val);

  protected:
    byte color[3]{};

  private:
    AbstractLedStrip* _brightStrip;
};