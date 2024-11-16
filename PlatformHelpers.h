#ifndef PLATFORM_HELPERS_H
#define PLATFORM_HELPERS_H

#include <stdint.h>  // for uint32_t and other fixed-width integer types
#include <math.h>
#define PI 3.14159265358979323846

enum class ClusterNameEnum {
    largeCluster,
    smallCluster
};

struct PlatformAgnosticPixel {
 uint8_t r;
 uint8_t g;
 uint8_t b;
 
 PlatformAgnosticPixel() : r(0), g(0), b(0) {}
 PlatformAgnosticPixel(uint8_t red, uint8_t green, uint8_t blue): r(red), g(green), b(blue) {}
};


PlatformAgnosticPixel myBlend(PlatformAgnosticPixel color1, PlatformAgnosticPixel color2, uint8_t blendAmount);
void setupLEDs();
void Show();
void setPixel(PlatformAgnosticPixel, uint16_t, ClusterNameEnum);
void setBrightness(uint8_t);

////// SEEED feather sense
#define FlowFeatherSense "FlowFeatherSense"
#define CLUSTER_1_PIN 3
#define CLUSTER_2_PIN 0
#define CLUSTER_1_COUNT 2
#define CLUSTER_2_COUNT 6

////////Flow Baton Arduino Mini v 1
// #define FlowArdinoMini "FlowArdinoMini"
// #define CLUSTER_1_PIN 9     
// #define CLUSTER_2_PIN 5
// #define CLUSTER_1_COUNT 6
// #define CLUSTER_2_COUNT 3


// ESP32 car strip
// #define PimpMyRide "PimpMyRide"
// #define CLUSTER_1_PIN 18     
// #define CLUSTER_2_PIN 5
// #define CLUSTER_1_COUNT 144
// #define CLUSTER_2_COUNT 0
// Check if ESP32 is used and include FastLED if true

#if defined(PimpMyRide) || defined(FlowArdinoMini)
    #include <FastLED.h>
    extern CRGB ledCluster1[CLUSTER_1_COUNT];
    extern CRGB ledCluster2[CLUSTER_2_COUNT];
#elif defined(FlowFeatherSense)
    #include <Adafruit_NeoPixel.h>
#endif

#endif