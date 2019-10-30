#pragma once

#include "Animation.h"
#include "../BlendManipulations.h"
#include "../framework.h"

// Neo fire animation by Robert Ulbricht
class NeoFire : public BlendManipulations, public Animation {
  public:
    NeoFire(AbstractLedStrip* strip, byte duration);

    void Init() override;
    void Show() override;

  private:
    uint32_t color;
    char pause;
    const uint32_t c1 = 80;
    const uint32_t c2 = 25;
};