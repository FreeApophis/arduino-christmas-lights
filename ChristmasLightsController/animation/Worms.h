#pragma once

#include "Animation.h"
#include "../BrightnessManipulation.h"
#include "../framework.h"

// Several worms are moving randomly
class Worms : public BrightnessManipulation, public Animation {
  public:
    Worms(AbstractLedStrip* strip);
    virtual void init();
    virtual void show();

  private:
    void add();
    void die(byte index);
    struct worm {
        uint32_t color;
        int pos;
        bool fwd;
    };
    struct worm w[5];
    byte active;
};
