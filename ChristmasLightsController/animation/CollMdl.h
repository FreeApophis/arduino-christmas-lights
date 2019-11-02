#pragma once

#include "animation/Animation.h"
#include "framework.h"

// Random colors from left and right move to the center
class CollMdl : public Animation {
  public:
    CollMdl(AbstractLedStrip* strip, byte duration);

    void Init() override;
    void Show() override;

  private:
    void newColors();
    uint32_t cl, cr;
    int l, r, ml, mr;
    bool clr;
};
