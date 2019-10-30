#include "LightsController.h"

#include "AnimationManager.h"
#include "SimulatedLedStrip.h"
#include "animation/Animation.h"
#include "animation/CenterRun.h"
#include "animation/CollEnd.h"
#include "animation/CollMdl.h"
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
#include "animation/Toward.h"
#include "animation/TowardRain.h"
#include "animation/WalkSeven.h"
#include "animation/Worms.h"
#include "clearance/ClearFade.h"
#include "clearance/ClearFromCenter.h"
#include "clearance/ClearHalf.h"
#include "clearance/ClearSide.h"
#include "clearance/Clearance.h"
#include "clearance/EatFromCenter.h"
#include "framework.h"

const byte NEO_BRGHT = 100;
//const byte NEO_PIN = 6; // Pin of Neopixel Strip
const byte StripSize = 100; // Length of Neopixel Strip
const byte min_time = 30;   // Minimal sequence show time (secons)
//
//// Parameter 1 = number of pixels in strip
//// Parameter 2 = Arduino pin number (most are valid)
//// Parameter 3 = pixel type flags, add together as needed:
////   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
////   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
////   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
////   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
//Adafruit_NeoPixel strip = Adafruit_NeoPixel(StripSize, NEO_PIN, NEO_GRB + NEO_KHZ800);

SimulatedLedStrip strip(StripSize);

// Instantiate Animations
ColorWipe colorWipe(&strip, min_time);
ColorWalk colorWalk(&strip, min_time);
RandomCreep randomCreep(&strip, min_time);
Rainbow rainbow(&strip, min_time);
RainCycle rainCycle(&strip, min_time);
RainFull rainFull(&strip, min_time);
ColorWave colorWave(&strip, min_time);
LightUp lightUp(&strip, min_time);
Sparks sparks(&strip, min_time);
RandomFade randomFade(&strip, min_time);
CenterRun centerRun(&strip, min_time);
ShineSeven shineSeven(&strip, min_time);
WalkSeven walkSeven(&strip, min_time);
FlashSeven flashSeven(&strip, min_time);
ShineFlash shineFlash(&strip, min_time);
MergeOne mergeOn(&strip, min_time);
MergeWave mergeWave(&strip, min_time);
CollideOne collideOne(&strip);
NeoFire neoFire(&strip, min_time);
EvenOdd evenOdd(&strip, min_time);
CollMdl collMdl(&strip, min_time);
CollEnd collEnd(&strip, min_time);
RainBlend rainBlend(&strip, min_time);
ColorSwing swing(&strip, min_time);
SingleColorSwing SingleColorSwing(&strip);
RandomFill randomFill(&strip, min_time);
SingleWave singleWave(&strip);
Worms worms(&strip);
Interference interfer(&strip, min_time);
Toward toward(&strip, min_time);
TowardRain towardRain(&strip, min_time);
LightHouse lightHouse(&strip);
RandomDrops randomDrops(&strip);
SolitonCreep solitonCreep(&strip, min_time);

// Instantiate Clearance Animations
ClearSide clrSide(&strip);
ClearFromCenter clearFromCenter(&strip);
ClearFade clearFade(&strip);
EatFromCenter eatFromCenter(&strip);
ClearHalf clearHalf(&strip);

Animation* animations[] = {
    &colorWipe,
    &colorWalk,
    &randomCreep,
    &rainbow,
    &rainCycle,
    &rainFull,
    &colorWave,
    &lightUp,
    &sparks,
    &randomFade,
    &centerRun,
    &shineSeven,
    &walkSeven,
    &flashSeven,
    &shineFlash,
    &mergeOn,
    &mergeWave,
    &collideOne,
    &neoFire,
    &evenOdd,
    &collMdl,
    &collEnd,
    &rainBlend,
    &swing,
    &SingleColorSwing,
    &randomFill,
    &singleWave,
    &worms,
    &interfer,
    &toward,
    &towardRain,
    &lightHouse,
    &randomDrops,
    &solitonCreep,
};

Clearance* clearances[] = {
    &clrSide,
    &clearFromCenter,
    &clearFade,
    &eatFromCenter,
    &clearHalf,
};
const byte num_anim = sizeof(animations) / sizeof(Animation*);
const byte num_clr = sizeof(clearances) / sizeof(Clearance*);

AnimationManager mgr(animations, num_anim, clearances, num_clr, &strip);

void setup()
{
    //Serial.begin(9600);

    //uint32_t rnd = 0;
    //for (byte i = A0; i < A4; ++i) {
    //    pinMode(i, INPUT);
    //    rnd <<= 6;
    //    rnd += analogRead(i);
    //}
    //randomSeed(rnd);

    strip.begin();
    strip.setBrightness(NEO_BRGHT);
    strip.show(); // Initialize all pixels to 'off'
    mgr.init();
}

void loop()
{
    mgr.show();
}