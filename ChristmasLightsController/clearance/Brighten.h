#pragma once

#include "Clearance.h"

// Clear the strip from the ether side
class Brighten : public Clearance {
  public:
    Brighten(AbstractLedStrip* strip);

    void Init() override;
    void Show() override;

  private:
    int _step;
};
