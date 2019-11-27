#pragma once

#include "framework.h"
#include "AbstractLedStrip.h"
#ifdef _MSC_VER
#include <cstdint>
#endif

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


