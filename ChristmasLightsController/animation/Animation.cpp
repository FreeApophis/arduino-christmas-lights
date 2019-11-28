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

uint16_t Animation::AnimationId() const
{
    return _animationId;
}

bool Animation::IsComplete() const
{
    return _complete;
}

bool Animation::NeedsClearance() const
{
    return _needsClearance;
}

void Animation::SetNeedsClearance(const bool clear)
{
    _needsClearance = clear;
}

uint16_t Animation::MinPeriod() const
{
    return _minPeriod;
}

uint16_t Animation::MaxPeriod() const
{
    return _maxPeriod;
}
