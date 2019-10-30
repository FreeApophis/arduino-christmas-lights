#pragma once

#include "Animation.h"
#include "../framework.h"

// Random  colors toward each other
class Toward : public Animation {
  public:
    Toward(AbstractLedStrip* strip, byte duration);
    virtual void init() { w = random(256); }
    virtual void show();

  private:
    byte w;
};
