#pragma once
#include "AbstractLedStrip.h"
#include "animation/Animation.h"

#include "framework.h"

// Walk the dots one after the other with a color
class ColorWalk final : public Animation {
  public:
    explicit ColorWalk(AbstractLedStrip* strip);

    auto Init() -> void override;
    auto Show() -> void override;

  private:
    int _index;
    byte _period;
    bool _isForward;
    byte _wheelIndex;
};
