#pragma once

#include "../framework.h"
#include "Animation.h"

class AbstractLedStrip;

// Fill the dots one after the other with a color
class ColorWipe : public Animation {
  public:
    ColorWipe(AbstractLedStrip* strip, byte duration);
    virtual void Init();
    virtual void Show();

    ~ColorWipe() = default;

  private:
    byte w;
    int index;
    bool fwd;
};
