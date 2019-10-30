#pragma once

#include "Animation.h"
#include "../framework.h"

// Single color swing
class SingleColorSwing : public Animation {
  public:
    SingleColorSwing(AbstractLedStrip* strip);
    virtual void init();
    virtual void show();

  private:
    uint32_t color;
    int len, index;
    bool fwd;
    byte w;
};