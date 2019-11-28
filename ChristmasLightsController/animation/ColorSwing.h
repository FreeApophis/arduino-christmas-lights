#pragma once

#include "animation/Animation.h"
#include "manipulation/Crawl.h"

#include "framework.h"

// Color swing
class ColorSwing : public Animation {
  public:
    ColorSwing(AbstractLedStrip* strip, byte duration);

    void Init() override;
    void Show() override;

  private:
    Crawl _crawl;
    int len, index;
    byte w;
    bool rnd;
};
