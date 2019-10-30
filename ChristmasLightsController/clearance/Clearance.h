#pragma once

#include "../framework.h"
#include "../AbstractLedStrip.h"
#include <cstdint>

class AbstractLedStrip;

class Clearance {
  public:
    Clearance(AbstractLedStrip* strip);
    virtual void init() = 0;
    virtual void show() = 0;
    bool isComplete() const;
    bool fade(uint16_t index, byte val);
    bool fadeAll(byte val);

  protected:
    AbstractLedStrip* _strip;
    bool complete;
};


