#pragma once

#include "Clearance.h"

// Clear the strip from the ether side
class ClearFade : public Clearance {
  public:
    ClearFade(AbstractLedStrip* strip);

    virtual void init();
    virtual void show();

  private:
    byte decrement;
};
