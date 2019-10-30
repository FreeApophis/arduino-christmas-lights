#pragma once

#include "Clearance.h"

// Clear the strip from the ether side
class ClearFade : public Clearance {
  public:
    ClearFade(AbstractLedStrip* strip);

    void Init() override;
    void Show() override;

  private:
    byte decrement{};
};
