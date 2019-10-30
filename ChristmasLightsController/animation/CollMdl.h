#pragma once

#include "Animation.h"
#include "../BlendManipulations.h"
#include "../framework.h"

// Random colors from left and right move to the center
class CollMdl : public BlendManipulations, public Animation {
  public:
    CollMdl(AbstractLedStrip* strip, byte duration);
    virtual void Init();
    virtual void Show();

  private:
    void newColors();
    uint32_t cl, cr;
    int l, r, ml, mr;
    bool clr;
};
