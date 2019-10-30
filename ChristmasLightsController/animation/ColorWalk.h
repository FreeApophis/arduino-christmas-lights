#pragma once
#include "../framework.h"
#include "../AbstractLedStrip.h"
#include "Animation.h"

// Walk the dots one after the other with a color
class ColorWalk : public Animation {
  public:
    ColorWalk(AbstractLedStrip* strip, byte duration);
    virtual void Init();
    virtual void Show();

  private:
    int index;
    byte period;
    bool fwd;
    byte w;
};
