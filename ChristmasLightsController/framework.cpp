#include "framework.h"

int random(int maxVal)
{
    return 0;
}

int random(int minVal, int maxVal)
{
    return minVal;
}

uint32_t ToColor(uint8_t r, uint8_t g, uint8_t b)
{
    return static_cast<uint32_t>(r) << 16 | static_cast<uint32_t>(g) << 8 | b;
}

unsigned long millis()
{
    return 0;
}

void delay(unsigned long)
{
}
