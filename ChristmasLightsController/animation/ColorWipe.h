#pragma once

#include "animation/Animation.h"

class AbstractLedStrip;

// Fill the dots one after the other with a color
class ColorWipe final : public Animation {
  public:
    explicit ColorWipe(AbstractLedStrip* strip);

    auto Init() -> void override;
    auto Show() -> void override;

  private:
    byte _wheelIndex;
    int _index;
    bool _isForward;
};
