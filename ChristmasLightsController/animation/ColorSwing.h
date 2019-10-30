#pragma once

#include "../Crawl.h"
#include "../framework.h"
#include "Animation.h"

// Color swing
class ColorSwing : public Crawl, public Animation {
  public:
    ColorSwing(AbstractLedStrip* strip, byte duration);
    virtual void Init();
    virtual void Show();

  private:
    int len, index;
    byte w;
    bool rnd;
};
