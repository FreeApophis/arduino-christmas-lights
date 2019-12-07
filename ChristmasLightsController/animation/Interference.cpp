#include "Interference.h"

#include "manipulation/ColorManipulation.h"

#include <cstdlib>

Interference::Interference(AbstractLedStrip* strip) :
    Animation(0x0108, strip, 6, 10),
    _startTime(0),
    _positions{},
    _start{},
    _wheelIndex{},
    _active(0)
{
}

auto Interference::Init() -> void
{
    _active = 0;
    _startTime = 0;
    Add();
}

auto Interference::Show() -> void
{
    const int pixelCount = _strip->numPixels();

    for (auto index = 0; index < pixelCount; ++index) {
        _strip->setPixelColor(index, NextColor(index));
    }
    ++_startTime;
    if (_startTime % 64 == 0) {
        for (byte index = 0; index < _active; ++index) {
            _wheelIndex[index] += 4;
        }
    }

    if (!random(20))
        Add();
}

auto Interference::Add() -> void
{
    if (_active >= interferenceCount) {
        return;
    }
    _positions[_active] = random(_strip->numPixels());
    _wheelIndex[_active] = random(256);
    _start[_active] = _startTime;
    _active++;
}

auto Interference::Clear(const int position, const byte source) -> uint32_t
{
    uint32_t c = 0;
    const int sourcePosition = _positions[source];
    int delta = _startTime - _start[source];
    delta -= abs(position - sourcePosition);
    if (delta < 0) {
        return c; // The wave is not here yet
    }
    delta %= 64; // The wave period
    // Half way
    const byte elm = (delta < 32 ? 31 - delta : delta - 64) << 3;

    const auto color = ColorFromColorWheel(_wheelIndex[source]);
    for (byte index = 0; index < 3; ++index) {
        int max_c = (color >> (8 * index)) & 0xff;
        max_c -= elm;
        if (max_c < 0)
            max_c = 0;
        uint32_t nc = max_c;
        nc <<= 8 * index;
        c |= nc;
    }
    return c;
}

auto Interference::NextColor(const int position) -> uint32_t
{
    uint32_t result = 0;

    for (byte index = 0; index < _active; ++index) {
        result = ColorSuperPosition(result, Clear(position, index));
    }

    return result;
}
