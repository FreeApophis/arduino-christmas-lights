#include "Clear.h"

auto Clear(AbstractLedStrip* strip) -> void
{
    constexpr int32_t black = 0;

    for (auto index = 0; index < strip->numPixels(); ++index) {
        strip->setPixelColor(index, black);
    }
}
