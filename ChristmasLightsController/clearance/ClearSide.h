#pragma once

#include "Clearance.h"

// Clear the strip from the other side
class ClearSide final : public Clearance {
  public:
    explicit ClearSide(AbstractLedStrip* strip);
    auto Init() -> void override;
    auto Show() -> void override;

  private:
    uint32_t _color;
    int _index;
    bool _isForward;
};