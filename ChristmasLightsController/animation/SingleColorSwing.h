#pragma once

#include "Animation.h"
#include "../framework.h"

// Single color swing
class SingleColorSwing : public Animation {
  public:
    SingleColorSwing(AbstractLedStrip* strip);
    virtual void Init();
    virtual void Show();

  private:
    uint32_t color;
    int len, index;
    bool fwd;
    byte w;
};