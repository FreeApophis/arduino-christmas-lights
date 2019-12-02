#include "WarmWhiteShimmer.h"

#include "../manipulation/ColorManipulation.h"
#include "../manipulation/RandomWalk.h"

const unsigned char MaxBrightness = 160; // cap on LED brighness
const unsigned char ChangeAmount = 4;   // size of random walk step

WarmWhiteShimmer::WarmWhiteShimmer(AbstractLedStrip* strip) :
    Animation(0xb001, strip, 2, 2)
{
}

void WarmWhiteShimmer::Init()
{
}

void WarmWhiteShimmer::Show()
{
    bool dimOnly = false;

    for (uint16_t index = 0; index < _strip->numPixels(); index += 2) {
        // randomly walk the brightness of every even LED
        const auto redPart = RandomWalk(ExtractRed(_strip->getPixelColor(index)), MaxBrightness, ChangeAmount, dimOnly ? 1 : 2);

        // warm white: red = x, green = 0.8x, blue = 0.125x
        _strip->setPixelColor(index, ToColor(redPart, redPart * 4 / 5, redPart >> 3));

        // every odd LED gets set to a quarter the brighness of the preceding even LED
        if (index + 1 < _strip->numPixels()) {
            _strip->setPixelColor(index + 1, ToColor(redPart >> 2, redPart / 5, (redPart >> 5)));
        }
    }
}
