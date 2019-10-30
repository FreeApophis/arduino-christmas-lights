#include "Helper.h"

#include "framework.h"

// Input a value 0 to 255 to get a color value. The colours are a transition r - g - b - back to r.
uint32_t ColorFromColorWheel(byte WheelPos)
{
    WheelPos = 255 - WheelPos;
    if (WheelPos < 85) {
        return ToColor(255 - WheelPos * 3, 0, WheelPos * 3);
    }

    if (WheelPos < 170) {
        WheelPos -= 85;
        return ToColor(0, WheelPos * 3, 255 - WheelPos * 3);
    }
    WheelPos -= 170;
    return ToColor(WheelPos * 3, 255 - WheelPos * 3, 0);
}