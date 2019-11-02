#pragma once

#include "AbstractLedStrip.h"

#include "framework.h"

#include <cstdint>

class AbstractLedStrip;

class Clearance {
  public:
    explicit Clearance(AbstractLedStrip* strip);
    virtual ~Clearance() = default;

    virtual void Init() = 0;
    virtual void Show() = 0;

    bool IsComplete() const;
    bool Fade(uint16_t index, byte val);
    bool FadeAll(byte val);

  protected:
    AbstractLedStrip* _strip;
    bool _complete;
};
