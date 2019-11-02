#pragma once

#include "Crawl.h"
#include "framework.h"
#include "animation/Animation.h"

// Color swing
class ColorSwing : public Crawl, public Animation {
  public:
    ColorSwing(AbstractLedStrip* strip, byte duration);

    void Init() override;
    void Show() override;

  private:
    int len, index;
    byte w;
    bool rnd;
};
