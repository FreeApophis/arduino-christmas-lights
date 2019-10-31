#include "framework.h"

#include <random>

std::random_device randomDevice;
std::mt19937 mt(randomDevice());

int random(int maxVal)
{
    const std::uniform_int_distribution<int> dist(0, maxVal);
    return dist(mt);
}

int random(int minVal, int maxVal)
{
    const std::uniform_int_distribution<int> dist(minVal, maxVal);
    return dist(mt);
}

uint32_t ToColor(uint8_t r, uint8_t g, uint8_t b)
{
    return static_cast<uint32_t>(r) << 16 | static_cast<uint32_t>(g) << 8 | b;
}

long _millis = 0;

void incrementMillis()
{
    _millis += 100;
}

unsigned long millis()
{
    return _millis;
}

void delay(unsigned long)
{
}
