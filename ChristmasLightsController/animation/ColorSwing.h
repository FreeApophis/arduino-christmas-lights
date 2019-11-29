#pragma once

#include "animation/Animation.h"
#include "manipulation/Crawl.h"

#include "framework.h"

// Color swing
class ColorSwing : public Animation {
  public:
    ColorSwing(AbstractLedStrip* strip);

    void Init() override;
    void Show() override;

  private:
    Crawl _crawl;
    int _length;
    int _index;
    byte w;
    bool rnd;
};
