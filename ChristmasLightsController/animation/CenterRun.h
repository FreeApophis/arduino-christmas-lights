#pragma once

#include "Animation.h"
#include "../framework.h"

// Lights run from the center
class CenterRun : public Animation {
  public:
    CenterRun(AbstractLedStrip* strip, byte duration);

    void Init() override;
    void Show() override;

  private:
    uint32_t color;
    int m, l, r;
};
