#include "animation/Animation.h"

Animation::Animation(AbstractLedStrip* strip, byte duration, byte minPeriod, byte maxPeriod) :
    _strip(strip),
    _needsClear(false),
    _complete(true),
    _minPeriod(minPeriod),
    _maxPeriod(maxPeriod),
    _showTime(duration)
{
}

bool Animation::IsComplete() const
{
    return _complete;
}

bool Animation::NeedsClear() const
{
    return _needsClear;
}

void Animation::SetNeedsClear(const bool clear)
{
    _needsClear = clear;
}

uint32_t Animation::ShowTime() const
{
    return _showTime;
}

uint16_t Animation::MinPeriod() const
{
    return _minPeriod;
}

uint16_t Animation::MaxPeriod() const
{
    return _maxPeriod;
}
