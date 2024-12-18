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
 float opacity;
 
    PlatformAgnosticPixel() : r(0), g(0), b(0), opacity(1.0f) {}
    // Constructor to initialize r, g, b with custom values, opacity defaults to 1
    PlatformAgnosticPixel(uint8_t red, uint8_t green, uint8_t blue)
        : r(red), g(green), b(blue), opacity(1.0f) {}

    // Constructor to initialize r, g, b and opacity with custom values
    PlatformAgnosticPixel(uint8_t red, uint8_t green, uint8_t blue, float op)
        : r(red), g(green), b(blue), opacity(op) {}
};


PlatformAgnosticPixel myBlend(PlatformAgnosticPixel color1, PlatformAgnosticPixel color2, uint8_t blendAmount);
void setupLEDs();
void Show();
void setPixel(PlatformAgnosticPixel, uint16_t, ClusterNameEnum);
void setBrightness(uint8_t);



////////Flow Baton Arduino Mini v 1
// #define NeoPixelRequired "NeoPixelRequired"
// #define CLUSTER_1_PIN 3    
// #define CLUSTER_2_PIN 5
// #define CLUSTER_1_COUNT 150
// #define CLUSTER_2_COUNT 3


#define FastLEDEnabled "FastLEDEnabled"
#define CLUSTER_1_PIN 3
#define CLUSTER_2_PIN 5
#define CLUSTER_1_COUNT 6
#define CLUSTER_2_COUNT 2

#if defined(FastLEDEnabled)
    #include <FastLED.h>
    extern CRGB ledCluster1[CLUSTER_1_COUNT];
    extern CRGB ledCluster2[CLUSTER_2_COUNT];
#elif defined(NeoPixelRequired)
    #include <Adafruit_NeoPixel.h>
#endif
#endif


#if defined(FastLEDEnabled)
    #define COLOR_ORDER RGB 
#endif