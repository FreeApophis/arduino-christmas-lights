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

long _millis = 0;

void incrementMillis()
{
    _millis += 1000;
}

unsigned long millis()
{
    return _millis;
}

void delay(unsigned long)
{
}
