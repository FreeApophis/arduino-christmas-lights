#pragma once

#include "animation/Animation.h"
#include "manipulation/Crawl.h"

#include "framework.h"

// Color swing
class ColorSwing final : public Animation {
  public:
    explicit ColorSwing(AbstractLedStrip* strip);

    auto Init() -> void override;
    auto Show() -> void override;

  private:
    Crawl _crawl;
    int _length;
    int _index;
    byte _wheelIndex;
    bool _random;
};
