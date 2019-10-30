#include "ClearSide.h"

#include "../Helper.h"

ClearSide::ClearSide(AbstractLedStrip* strip) :
    Clearance(strip)
{
}

void ClearSide::init()
{
    complete = false;
    color = ColorFromColorWheel(random(256));
    fwd = random(2);
    if (fwd) {
        index = 0;
    } else {
        index = _strip->numPixels() - 1;
    }
}

void ClearSide::show()
{
    if (fwd) {
        if (index < int(_strip->numPixels())) {
            _strip->setPixelColor(index, color);
            if (index > 0)
                _strip->setPixelColor(index - 1, 0);
        }
        ++index;
        complete = (index >= int(_strip->numPixels()));
    } else {
        if (index >= 0) {
            _strip->setPixelColor(index, color);
            if (index < int(_strip->numPixels() - 1))
                _strip->setPixelColor(index + 1, 0);
        }
        --index;
        complete = (index < 0);
    }
}