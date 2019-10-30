#pragma once

#include "../framework.h"
#include "../AbstractLedStrip.h"
#include <cstdint>

class AbstractLedStrip;

class Clearance {
  public:
    Clearance(AbstractLedStrip* strip);

    virtual void Init() = 0;
    virtual void Show() = 0;

    bool IsComplete() const;
    bool Fade(uint16_t index, byte val);
    bool FadeAll(byte val);

  protected:
    AbstractLedStrip* _strip;
    bool _complete;
};


