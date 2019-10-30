#pragma once

#include "Animation.h"
#include "../framework.h"

// Lights run from the center
class CenterRun : public Animation {
  public:
    CenterRun(AbstractLedStrip* strip, byte duration);
    virtual void Init();
    virtual void Show();

  private:
    uint32_t color;
    int m, l, r;
};
