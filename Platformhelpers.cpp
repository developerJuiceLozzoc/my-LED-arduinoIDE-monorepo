#include "PlatformHelpers.h"

#if defined(PimpMyRide)
    #define COLOR_ORDER RGB
#elif defined(FlowArdinoMini)
    #define COLOR_ORDER GRB
#endif

#if defined(PimpMyRide) || defined(FlowArdinoMini)
  CRGB ledCluster1[CLUSTER_1_COUNT];
  CRGB ledCluster2[CLUSTER_2_COUNT];
#else
  #include <Adafruit_NeoPixel.h>
  Adafruit_NeoPixel ledCluster1 = Adafruit_NeoPixel(CLUSTER_1_COUNT, CLUSTER_1_PIN, NEO_RGB + NEO_KHZ800);
  Adafruit_NeoPixel ledCluster2 = Adafruit_NeoPixel(CLUSTER_2_COUNT, CLUSTER_2_PIN, NEO_RGB + NEO_KHZ800);
#endif

// Function to initialize the LED library
void setupLEDs() {
  #if defined(FlowArdinoMini)
    FastLED.addLeds<WS2811, CLUSTER_1_PIN, COLOR_ORDER>(ledCluster1, CLUSTER_1_COUNT);
    FastLED.addLeds<WS2811, CLUSTER_2_PIN, COLOR_ORDER>(ledCluster2, CLUSTER_2_COUNT);
  #elif defined(PimpMyRide)
    FastLED.addLeds<WS2812, CLUSTER_1_PIN, COLOR_ORDER>(ledCluster1, CLUSTER_1_COUNT);
    FastLED.addLeds<WS2812, CLUSTER_2_PIN, COLOR_ORDER>(ledCluster2, CLUSTER_2_COUNT);
  #else
    ledCluster1.begin();
    ledCluster1.setBrightness(255);  // Set initial brightness for NeoPixel
    ledCluster1.show();  // Initialize all pixels to 'off'
    ledCluster2.begin();
    ledCluster2.setBrightness(255);  // Set initial brightness for NeoPixel
    ledCluster2.show();  // Initialize all pixels to 'off'
  #endif
}

void setBrightness(uint8_t brightness) {
  #if defined(PimpMyRide) || defined(FlowArdinoMini)
    FastLED.setBrightness(brightness);
    FastLED.show();
  #else
    ledCluster2.setBrightness(brightness);
    ledCluster1.setBrightness(brightness);
    ledCluster2.show();
    ledCluster1.show();
  #endif
}


void Show() {
  #if defined(PimpMyRide) || defined(FlowArdinoMini)
    FastLED.show();
  #else
    ledCluster2.show();
    ledCluster1.show();
  #endif
}

void setPixel(PlatformAgnosticPixel pixel, uint16_t index, ClusterNameEnum cluster) {
  #if defined(PimpMyRide)
    ledCluster1[index] = CRGB(pixel.r, pixel.g, pixel.b);
  #elif defined(FlowFeatherSense)
    if(cluster == ClusterNameEnum::largeCluster) {
      ledCluster1.setPixelColor(index, ledCluster1.Color(pixel.r, pixel.g, pixel.b));
    } else {
      ledCluster2.setPixelColor(index, ledCluster2.Color(pixel.r, pixel.g, pixel.b));
    }
  #elif defined(FlowArdinoMini)
    if(cluster == ClusterNameEnum::largeCluster) {
      ledCluster1[index] = CRGB(pixel.r, pixel.g, pixel.b);
    } else {
      ledCluster2[index] = CRGB(pixel.r, pixel.g, pixel.b);
    }
  #endif
}


PlatformAgnosticPixel myBlend(PlatformAgnosticPixel color1, PlatformAgnosticPixel color2, uint8_t blendAmount) {
    PlatformAgnosticPixel result;
    result.r = color1.r + ((color2.r - color1.r) * blendAmount / 255);
    result.g = color1.g + ((color2.g - color1.g) * blendAmount / 255);
    result.b = color1.b + ((color2.b - color1.b) * blendAmount / 255);
    return result;
}
