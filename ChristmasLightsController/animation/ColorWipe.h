#pragma once

#include "animation/Animation.h"

class AbstractLedStrip;

// Fill the dots one after the other with a color
class ColorWipe : public Animation {
  public:
    ColorWipe(AbstractLedStrip* strip);

    void Init() override;
    void Show() override;

    ~ColorWipe() = default;

  private:
    byte w;
    int _index;
    bool fwd;
};
