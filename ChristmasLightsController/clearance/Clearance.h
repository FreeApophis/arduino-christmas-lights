#pragma once

#include "AbstractLedStrip.h"

#include "framework.h"

#include <cstdint>

class AbstractLedStrip;

class Clearance {
  public:
    explicit Clearance(AbstractLedStrip* strip);
    virtual ~Clearance() = default;

    Clearance(const Clearance& animation) = delete;
    Clearance(Clearance&& animation) = delete;
    auto operator=(const Clearance& animation) -> void = delete;
    auto operator=(Clearance&& animation) -> void = delete;

    virtual auto Init() -> void = 0;
    virtual auto Show() -> void = 0;

    auto IsComplete() const -> bool;
    auto Fade(uint16_t index, byte value) const -> bool;
    auto FadeAll(byte value) const -> bool;

  protected:
    AbstractLedStrip* _strip;
    bool _complete;
};
