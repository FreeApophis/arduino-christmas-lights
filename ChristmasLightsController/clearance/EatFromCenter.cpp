#include "EatFromCenter.h"

EatFromCenter::EatFromCenter(AbstractLedStrip* strip) :
    Clearance(strip)
{
}

void EatFromCenter::Init()
{
    _complete = false;
    remain = _strip->numPixels() / 2 + 1;
}

void EatFromCenter::Show()
{
    const int n = _strip->numPixels();
    const int c = n / 2;
    for (int i = c; i > 0; --i) {
        uint32_t c = _strip->getPixelColor(i - 1);
        _strip->setPixelColor(i, c);
    }
    for (int i = c; i < n - 1; ++i) {
        uint32_t c = _strip->getPixelColor(i + 1);
        _strip->setPixelColor(i, c);
    }
    _strip->setPixelColor(0, 0);
    _strip->setPixelColor(n - 1, 0);
    --remain;
    _complete = (remain <= 0);
}
