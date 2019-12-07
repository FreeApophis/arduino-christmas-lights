#pragma once

#include "AbstractLedStrip.h"

#include "framework.h"

class Animation {
  public:
    virtual ~Animation() = default;

    Animation(uint16_t animationId, AbstractLedStrip* strip, byte minPeriod, byte maxPeriod);

    Animation(const Animation& animation) = delete;
    Animation(Animation&& animation) = delete;
    auto operator=(const Animation& animation) -> void = delete;
    auto operator=(Animation&& animation) -> void = delete;

    virtual auto Init() -> void = 0;
    virtual auto Show() -> void = 0;

    auto AnimationId() const -> uint16_t;

    auto IsComplete() const -> bool;

    auto NeedsClearance() const -> bool;
    auto SetNeedsClearance(bool clear) -> void;

    auto MinPeriod() const -> uint16_t;
    auto MaxPeriod() const -> uint16_t;

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
