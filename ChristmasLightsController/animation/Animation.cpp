#include "animation/Animation.h"

Animation::Animation(uint16_t animationId, AbstractLedStrip* strip, byte minPeriod, byte maxPeriod) :
    _strip(strip),
    _needsClearance(false),
    _complete(true),
    _animationId(animationId),
    _minPeriod(minPeriod),
    _maxPeriod(maxPeriod)
{
}

auto Animation::AnimationId() const -> uint16_t
{
    return _animationId;
}

auto Animation::IsComplete() const -> bool
{
    return _complete;
}

auto Animation::NeedsClearance() const -> bool
{
    return _needsClearance;
}

auto Animation::SetNeedsClearance(const bool clear) -> void
{
    _needsClearance = clear;
}

auto Animation::MinPeriod() const -> uint16_t
{
    return _minPeriod;
}

auto Animation::MaxPeriod() const -> uint16_t
{
    return _maxPeriod;
}
