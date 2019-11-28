#include "RandomDrops.h"

#include "manipulation/ColorManipulation.h"

RandomDrops::RandomDrops(AbstractLedStrip* strip) :
    Animation(0x0113, strip, 9, 2, 7),
    _brightnessManipulation(strip)
{
}

void RandomDrops::Init()
{
    num = 0;
    add();
}

void RandomDrops::Show()
{
    int n = _strip->numPixels();
    for (byte i = 0; i < num; ++i) {
        if (++dr[i].TimeFrame > 7) { // Delete old drops
            dr[i].Position = dr[byte(num - 1)].Position;
            dr[i].TimeFrame = dr[byte(num - 1)].TimeFrame;
            --num;
            --i;
            continue;
        }
        int p = dr[i].Position - dr[i].TimeFrame;
        if (p < 0)
            p += n;
        uint32_t c1 = _strip->getPixelColor(p + 1);
        _brightnessManipulation.change(p + 1, -64);
        uint32_t c2 = _strip->getPixelColor(p);
        c2 = ColorSuperPosition(c1, c2);
        _strip->setPixelColor(p, c2);

        p = dr[i].Position + dr[i].TimeFrame;
        if (p >= n)
            p -= n;
        c1 = _strip->getPixelColor(p - 1);
        if (dr[i].TimeFrame > 1)
            _brightnessManipulation.change(p - 1, -32);
        c2 = _strip->getPixelColor(p);
        c2 = ColorSuperPosition(c1, c2);
        _strip->setPixelColor(p, c2);

        _brightnessManipulation.change(dr[i].Position, -64);
    }

    _brightnessManipulation.changeAll(-32);

    add();
}

void RandomDrops::add()
{
    if (num >= 16)
        return;
    int pos = random(_strip->numPixels());
    uint32_t c = _strip->getPixelColor(pos);
    if (c)
        return;
    c = ColorFromColorWheel(random(256));
    _strip->setPixelColor(pos, c);
    dr[byte(num)].Position = pos;
    dr[byte(num)].TimeFrame = 0;
    num++;
}