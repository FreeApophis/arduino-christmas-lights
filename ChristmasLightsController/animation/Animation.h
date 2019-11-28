#pragma once

#include "AbstractLedStrip.h"

#include "framework.h"

class Animation {
  public:
    virtual ~Animation() = default;

    Animation(uint16_t animationId, AbstractLedStrip* strip, byte duration, byte minPeriod, byte maxPeriod);

    virtual void Init() = 0;
    virtual void Show() = 0;

    uint16_t AnimationId() const;

    bool IsComplete() const;

    bool NeedsClearance() const;
    void SetNeedsClearance(bool clear);

    uint32_t ShowTime() const;

    uint16_t MinPeriod() const;
    uint16_t MaxPeriod() const;

  protected:
    AbstractLedStrip* _strip;
    bool _needsClearance; // Whether the strip have to be cleaned for the next loop
    bool _complete;   // Whether the animation can be changed to the next one

  private:
    uint16_t _animationId;
    byte _minPeriod; // The minimum period in tenth of second to show the stage
    byte _maxPeriod; // The maximum period in tenth of second to show the stage
    byte _showTime;  // The minimum time to show the sequence in 10-secons intervals
};
