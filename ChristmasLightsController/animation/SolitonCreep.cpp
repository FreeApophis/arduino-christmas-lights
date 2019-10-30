#include "SolitonCreep.h"

#include "../Helper.h"

#include <cstdlib>

SolitonCreep::SolitonCreep(AbstractLedStrip* strip, byte duration):
    Crawl(strip),
    Animation(strip, 9, 6, 14)
{
}

void SolitonCreep::Init()
{
    w = random(256);
    Crawl::fwd = random(2);
    change_direction = random(200, 500);
    newSoliton();
}

void SolitonCreep::Show()
{
    Crawl::step();

    if (--change_direction <= 0) {
        Crawl::fwd = !Crawl::fwd;
        change_direction = random(200, 500);
    }

    int pos = _strip->numPixels() - 1;
    if (Crawl::fwd)
        pos = 0;

    if (sol <= 4) {
        int i = abs(sol);
        _strip->setPixelColor(pos, dot[i]);
        ++sol;
    } else {
        if (--space >= 0) {
            _strip->setPixelColor(pos, 0);
        } else {
            newSoliton();
        }
    }
}

void SolitonCreep::newSoliton()
{
    sol = -3;
    uint32_t c = ColorFromColorWheel(w);
    dot[0] = c;
    w += 71;
    uint32_t r = c & 0xff;
    uint32_t g = (c >> 8) & 0xff;
    uint32_t b = (c >> 16) & 0xff;
    for (byte i = 1; i <= 4; ++i) {
        r >>= 1;
        g >>= 1;
        b >>= 1;
        uint32_t cc = b & 0xff;
        cc <<= 8;
        cc |= g & 0xff;
        cc <<= 8;
        cc |= r & 0xff;
        dot[i] = cc;
    }
    space = random(3, 10);

    int pos = _strip->numPixels() - 1;
    if (Crawl::fwd)
        pos = 0;
    _strip->setPixelColor(pos, dot[4]);
}