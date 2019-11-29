#pragma once
#include "AbstractLedStrip.h"
#include "animation/Animation.h"

#include "framework.h"

// Walk the dots one after the other with a color
class ColorWalk : public Animation {
  public:
    ColorWalk(AbstractLedStrip* strip);

    void Init() override;
    void Show() override;

  private:
    int _index;
    byte _period;
    bool fwd;
    byte w;
};
