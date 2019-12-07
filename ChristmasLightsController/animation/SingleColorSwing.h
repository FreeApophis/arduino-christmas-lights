#pragma once

#include "animation/Animation.h"

#include "framework.h"

// Single color swing
class SingleColorSwing final : public Animation {
  public:
    explicit SingleColorSwing(AbstractLedStrip* strip);

    auto Init() -> void override;
    auto Show() -> void override;

  private:
    uint32_t _color;
    int _length;
    int _index;
    bool _isForward;
    byte _wheelIndex;
};