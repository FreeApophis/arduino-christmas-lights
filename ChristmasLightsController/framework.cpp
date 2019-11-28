#include "framework.h"

#include <random>

std::random_device randomDevice;
std::seed_seq seed{randomDevice(), randomDevice()};
std::mt19937 mt(seed);

int random(int maxVal)
{
    const std::uniform_int_distribution<int> dist(0, maxVal - 1);
    return dist(mt);
}

int random(int minVal, int maxVal)
{
    const std::uniform_int_distribution<int> dist(minVal, maxVal - 1);
    return dist(mt);
}

long _millis = 0;

void incrementMillis(long millis)
{
    _millis += millis;
}

unsigned long millis()
{
    return _millis;
}

void delay(unsigned long)
{
}
