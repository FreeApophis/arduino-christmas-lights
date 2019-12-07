#pragma once

#include "animation/Animation.h"

#include "framework.h"

constexpr int interferenceCount = 3;

// Show interference from many sources
class Interference final : public Animation {
  public:
    explicit Interference(AbstractLedStrip* strip);

    auto Init() -> void override;
    auto Show() -> void override;

  private:
    auto Add() -> void;
    auto Clear(int position, byte source) -> uint32_t;
    auto NextColor(int position) -> uint32_t;

    int _startTime;                      // Time the animation starts (in cycles)
    int _positions[interferenceCount];   // The position of the source
    int _start[interferenceCount];       // Time when the source activated
    byte _wheelIndex[interferenceCount]; // Wheel Color index of the source
    byte _active;                        // The number of active sources
};
