#pragma once

#include "Animation.h"
#include "../BlendManipulations.h"
#include "../framework.h"

// Rainbow colors blend
class RainBlend : public BlendManipulations, public Animation {
  public:
    RainBlend(AbstractLedStrip* strip, byte duration);
    virtual void Init() { index = 0; }
    virtual void Show();

  private:
    int index;
};
