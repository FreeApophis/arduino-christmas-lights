#pragma once

#include "animation/Animation.h"

#include "framework.h"

// Single color swing
class SingleColorSwing : public Animation {
  public:
    SingleColorSwing(AbstractLedStrip* strip);

    void Init() override;
    void Show() override;

  private:
    uint32_t color;
    int len, index;
    bool fwd;
    byte w;
};