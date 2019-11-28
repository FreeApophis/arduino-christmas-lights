#include "LightsController.h"

#include "AnimationManager.h"
#include "animation/Animation.h"
#include "animation/CenterRun.h"
#include "animation/ChristmasWave.h"
#include "animation/CollideOne.h"
#include "animation/ColorSwing.h"
#include "animation/ColorWalk.h"
#include "animation/ColorWave.h"
#include "animation/ColorWipe.h"
#include "animation/EvenOdd.h"
#include "animation/FlashSeven.h"
#include "animation/Interference.h"
#include "animation/LightHouse.h"
#include "animation/LightUp.h"
#include "animation/MergeOne.h"
#include "animation/MergeWave.h"
#include "animation/NeoFire.h"
#include "animation/RainBlend.h"
#include "animation/RainCycle.h"
#include "animation/RainFull.h"
#include "animation/Rainbow.h"
#include "animation/RandomCreep.h"
#include "animation/RandomDrops.h"
#include "animation/RandomFade.h"
#include "animation/RandomFill.h"
#include "animation/ShineFlash.h"
#include "animation/ShineSeven.h"
#include "animation/SingleColorSwing.h"
#include "animation/SingleWave.h"
#include "animation/SolitonCreep.h"
#include "animation/Sparks.h"
#include "animation/StaticColor.h"
#include "animation/Toward.h"
#include "animation/TowardRain.h"
#include "animation/WalkAcross.h"
#include "animation/WalkSeven.h"
#include "animation/WalkToCenter.h"
#include "animation/Worms.h"
#include "clearance/ClearFade.h"
#include "clearance/ClearFromCenter.h"
#include "clearance/ClearHalf.h"
#include "clearance/ClearSide.h"
#include "clearance/Clearance.h"
#include "clearance/EatFromCenter.h"
#include "manipulation/ColorManipulation.h"

#include "framework.h"

#ifdef ARDUINO
#else
#    include "SimulatedLedStrip.h"
#endif

#include <set>

const byte PixelBrightness = 100;

// Pin of Neopixel Strip
//const byte NEO_PIN = 6;

// Length of Neopixel Strip
const byte NumberOfPixels = 100;

// seconds
const byte MinimalSequenceShowTime = 30;
//
//// Parameter 1 = number of pixels in strip
//// Parameter 2 = Arduino pin number (most are valid)
//// Parameter 3 = pixel type flags, add together as needed:
////   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
////   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
////   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
////   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
//Adafruit_NeoPixel strip = Adafruit_NeoPixel(NumberOfPixels, NEO_PIN, NEO_GRB + NEO_KHZ800);

SimulatedLedStrip strip(NumberOfPixels);

// Instantiate Animations
// ID: 0x0100
CenterRun centerRun(&strip, MinimalSequenceShowTime);
// ID: 0x0101
CollideOne collideOne(&strip);
// ID: 0x0102
ColorSwing colorSwing(&strip, MinimalSequenceShowTime);
// ID: 0x0103
ColorWalk colorWalk(&strip, MinimalSequenceShowTime);
// ID: 0x0104
ColorWave colorWave(&strip, MinimalSequenceShowTime);
// ID: 0x0105
ColorWipe colorWipe(&strip, MinimalSequenceShowTime);
// ID: 0x0106
EvenOdd evenOdd(&strip, MinimalSequenceShowTime);
// ID: 0x0107
FlashSeven flashSeven(&strip, MinimalSequenceShowTime);
// ID: 0x0108
Interference interference(&strip, MinimalSequenceShowTime);
// ID: 0x0109
LightHouse lightHouse(&strip);
// ID: 0x010a
LightUp lightUp(&strip, MinimalSequenceShowTime);
// ID: 0x010b
MergeOne mergeOn(&strip, MinimalSequenceShowTime);
// ID: 0x010c
MergeWave mergeWave(&strip, MinimalSequenceShowTime);
// ID: 0x010d
NeoFire neoFire(&strip, MinimalSequenceShowTime);
// ID: 0x010e
RainBlend rainBlend(&strip, MinimalSequenceShowTime);
// ID: 0x010f
RainCycle rainCycle(&strip, MinimalSequenceShowTime);
// ID: 0x0110
RainFull rainFull(&strip, MinimalSequenceShowTime);
// ID: 0x0111
Rainbow rainbow(&strip, MinimalSequenceShowTime);
// ID: 0x0112
RandomCreep randomCreep(&strip, MinimalSequenceShowTime);
// ID: 0x0113
RandomDrops randomDrops(&strip);
// ID: 0x0114
RandomFade randomFade(&strip, MinimalSequenceShowTime);
// ID: 0x0115
RandomFill randomFill(&strip, MinimalSequenceShowTime);
// ID: 0x0116
ShineFlash shineFlash(&strip, MinimalSequenceShowTime);
// ID: 0x0117
ShineSeven shineSeven(&strip, MinimalSequenceShowTime);
// ID: 0x0118
SingleColorSwing singleColorSwing(&strip);
// ID: 0x0119
SingleWave singleWave(&strip);
// ID: 0x011a
SolitonCreep solitonCreep(&strip, MinimalSequenceShowTime);
// ID: 0x011b
Sparks sparks(&strip, MinimalSequenceShowTime);
// ID: 0x011c
Toward toward(&strip, MinimalSequenceShowTime);
// ID: 0x011d
TowardRain towardRain(&strip, MinimalSequenceShowTime);
// ID: 0x011e
WalkAcross walkAcross(&strip, MinimalSequenceShowTime);
// ID: 0x011f
WalkSeven walkSeven(&strip, MinimalSequenceShowTime);
// ID: 0x0120
WalkToCenter walkToCenter(&strip, MinimalSequenceShowTime);
// ID: 0x0121
Worms worms(&strip);

// ID: 0x0000
StaticColor off(&strip, MinimalSequenceShowTime, ToColor(0, 0, 0), 0x0000);
// ID: 0xaf00
StaticColor redColor(&strip, MinimalSequenceShowTime, ToColor(255, 0, 0), 0xaf00);
// ID: 0xa0f0
StaticColor greenColor(&strip, MinimalSequenceShowTime, ToColor(0, 255, 0), 0xa0f0);
// ID: 0xa00f
StaticColor blueColor(&strip, MinimalSequenceShowTime, ToColor(0, 0, 255), 0xa00f);

// ID: 0xb000
ChristmasWave christmasWave(&strip, MinimalSequenceShowTime);

// Instantiate Clearance Animations
ClearSide clearSide(&strip);
ClearFromCenter clearFromCenter(&strip);
ClearFade clearFade(&strip);
EatFromCenter eatFromCenter(&strip);
ClearHalf clearHalf(&strip);

Animation* animations[] = {
    &centerRun,
    &collideOne,
    &colorWalk,
    &colorWave,
    &colorWipe,
    &evenOdd,
    &flashSeven,
    &interference,
    &lightHouse,
    &lightUp,
    &mergeOn,
    &mergeWave,
    &neoFire,
    &rainBlend,
    &rainbow,
    &rainCycle,
    &rainFull,
    &randomCreep,
    &randomDrops,
    &randomFade,
    &randomFill,
    &shineFlash,
    &shineSeven,
    &singleColorSwing,
    &singleWave,
    &solitonCreep,
    &sparks,
    &colorSwing,
    &toward,
    &towardRain,
    &walkAcross,
    &walkSeven,
    &walkToCenter,
    &worms,
    &redColor,
    &greenColor,
    &blueColor,
};

Clearance* clearances[] = {
    &clearSide,
    &clearFromCenter,
    &clearFade,
    &eatFromCenter,
    &clearHalf,
};

template<typename TElement, int NSize>
bool CheckAnimationIds(TElement (&animations)[NSize])
{
    std::set<uint16_t> ids;
    for (const auto animation : animations) {
        if (ids.find(animation->AnimationId()) == ids.end()) {
            ids.insert(animation->AnimationId());
        } else {
            return false;
        }
    }

    return true;
}

template<typename TElement, int NSize>
int arraySize(TElement (&array)[NSize])
{
    return NSize;
}

AnimationManager mgr(&strip, animations, arraySize(animations), clearances, arraySize(clearances));

void randomize()
{
}

uint16_t setup()
{
    randomize();

    if (!CheckAnimationIds(animations)) {
        return 0;
    }

    strip.begin();
    strip.setBrightness(PixelBrightness);
    strip.show(); // Initialize all pixels to 'off'
    mgr.Init(&christmasWave);

    return strip.numPixels();
}

uint32_t* loop(long millis)
{
    mgr.Show();

    incrementMillis(millis);
    return strip.CurrentPixels().data();
}

void setAnimation(unsigned short animationId)
{
    mgr.StartAnimation(animationId);
}

unsigned short currentAnimationId()
{
    return mgr.CurrentAnimationId();
}
