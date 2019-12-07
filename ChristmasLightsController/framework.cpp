#include "framework.h"

#include <random>

std::random_device randomDevice;
std::seed_seq seed{randomDevice(), randomDevice()};
std::mt19937 mt(seed);

auto random(int maxVal) -> int
{
    const std::uniform_int_distribution<int> dist(0, maxVal - 1);
    return dist(mt);
}

auto random(int minVal, int maxVal) -> int
{
    const std::uniform_int_distribution<int> dist(minVal, maxVal - 1);
    return dist(mt);
}

long _millis = 0;

auto incrementMillis(long millis) -> void
{
    _millis += millis;
}

auto millis() -> unsigned long
{
    return _millis;
}

auto delay(unsigned long) -> void
{
}
