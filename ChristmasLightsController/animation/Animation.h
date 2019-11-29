#pragma once

#include "AbstractLedStrip.h"

#include "framework.h"

class Animation {
  public:
    virtual ~Animation() = default;

    Animation(uint16_t animationId, AbstractLedStrip* strip, byte minPeriod, byte maxPeriod);

    virtual void Init() = 0;
    virtual void Show() = 0;

    uint16_t AnimationId() const;

    bool IsComplete() const;

    bool NeedsClearance() const;
    void SetNeedsClearance(bool clear);

    uint16_t MinPeriod() const;
    uint16_t MaxPeriod() const;

  protected:
    AbstractLedStrip* _strip;
    
    // Whether the strip have to be cleaned for the next loop
    bool _needsClearance;
    
    // Whether the animation can be changed to the next one
    bool _complete;       

  private:
    uint16_t _animationId;
    
    // The minimum time for a single step in this animation (in centiseconds)
    byte _minPeriod;
    
    // The maximum time for a single step in this animation (in centiseconds)
    byte _maxPeriod; 
};
