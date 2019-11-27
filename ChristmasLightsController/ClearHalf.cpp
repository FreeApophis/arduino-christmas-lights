#include "ClearHalf.h"

void ClearHalf::Init()
{
    _complete = false;
    one_step = _strip->numPixels() / 2;
}

void ClearHalf::Show()
{
    for (uint16_t i = 0; i < _strip->numPixels(); i += one_step) {
        if (i > 0 || (one_step == 1))
            _strip->setPixelColor(i, 0);
    }
    _complete = ((one_step >>= 1) == 0);
}