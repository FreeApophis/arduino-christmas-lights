#pragma once

#include "../BlendManipulations.h"
#include "../framework.h"
#include "Animation.h"

// Random colors from left and right move to the other end
class CollEnd : public BlendManipulations, public Animation {
  public:
    CollEnd(AbstractLedStrip* strip, byte duration);

    void Init() override;
    void Show() override;

  private:
    void newColors();
    uint32_t cl, cr;
    int l, r, ml, mr;
};
