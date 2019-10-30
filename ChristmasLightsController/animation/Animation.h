#pragma once

#include "../AbstractLedStrip.h"
#include "../framework.h"

class Animation {
  public:
    virtual ~Animation() = default;

    Animation(AbstractLedStrip* strip, byte duration, byte minPeriod, byte maxPeriod) :
        _strip(strip),
        minPeriod(minPeriod),
        maxPeriod(maxPeriod),
        showTime(duration),
        needsClear(false),
        complete(true)
    {
    }

    virtual void init() = 0;
    virtual void show() = 0;
    void get_limits(byte& mi_p, byte& ma_p)
    {
        mi_p = minPeriod;
        ma_p = maxPeriod;
    }
    
    AbstractLedStrip* _strip;
    byte minPeriod;  // The minimum period in tenth of second to show the stage
    byte maxPeriod;  // The maximum period in tenth of second to show the stage
    byte showTime;   // The minimum time to show the sequence in 10-secons intervals
    bool needsClear; // Whether the strip have to be cleaned for the next loop
    bool complete;   // Whether the animation can be changed to the next one
};
