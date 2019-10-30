#pragma once

#include "Animation.h"
#include "../BlendManipulations.h"
#include "../framework.h"

// Rainbow colors blend
class RainBlend : public BlendManipulations, public Animation {
  public:
    RainBlend(AbstractLedStrip* strip, byte duration);
    virtual void init() { index = 0; }
    virtual void show();

  private:
    int index;
};
