#pragma once

#include "Clearance.h"

// Clear the strip from the ether side
class ClearFade final : public Clearance {
  public:
    explicit ClearFade(AbstractLedStrip* strip);

    auto Init() -> void override;
    auto Show() -> void override;

  private:
    byte _decrement;
};
