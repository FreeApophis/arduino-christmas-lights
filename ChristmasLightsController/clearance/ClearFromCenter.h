#pragma once

#include "Clearance.h"

// Clear the strip from the center to both ends
class ClearFromCenter final : public Clearance {
  public:
    explicit ClearFromCenter(AbstractLedStrip* strip);
    auto Init() -> void override;
    auto Show() -> void override;

  private:
    uint32_t color;
    int _left;
    int _right;
};
