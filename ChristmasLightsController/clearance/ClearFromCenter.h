#pragma once

#include "Clearance.h"

// Clear the strip from the center to both ends
class ClearFromCenter : public Clearance {
  public:
    ClearFromCenter(AbstractLedStrip* strip);
    virtual void init();
    virtual void show();

  private:
    uint32_t color;
    int l, r;
    bool fwd;
};
