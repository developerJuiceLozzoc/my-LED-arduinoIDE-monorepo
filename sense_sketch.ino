

#define PIN 0          // Define the pin connected to your LED strip
#define NUM_LEDS 144    // Define the number of LEDs in your strip

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, PIN, NEO_RGB + NEO_KHZ800); // Use NEO_RGB for WS2811

inline int intFromState(WandBatonAnimationState state) {
    return static_cast<int>(state);
}

inline void setNextState(WandBatonAnimationState *state) {
  const int currentState = intFromState(*state);
  const int totalState = 5;
  fill_solid(ledCluster1, CLUSTER_1_COUNT, CRGB::Black);  
  fill_solid(ledCluster2, CLUSTER_2_COUNT, CRGB::Black);  
    FastLED.setBrightness(255);

  FastLED.show();                        
  *state = static_cast<WandBatonAnimationState>((currentState + 1) % totalState);
}


void setup() {
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
}

WandBatonAnimationState currentState = WandBatonAnimationState::None;

void loop() {
  unsigned long currentMillis = millis(); 
  const int lengthOfAnimation = 8 * 1000; // 600 % millisoncs == 0 at 1 minute i think 4200 69
  CRGB pixel;


  if(
    (currentState == WandBatonAnimationState::None && currentMillis % 2000 == 0) ||
    (currentState != WandBatonAnimationState::None && currentMillis % lengthOfAnimation == 0)
   ) {
    setNextState(&currentState);
  }

  switch(currentState) {
    case WandBatonAnimationState::PinkAndGoldSexy:
      animatePGS();
      break;
    case WandBatonAnimationState::PurpleGreenPingPong:
      animatePGPP(currentMillis);
      break;
    case WandBatonAnimationState::RapidFlashSlowFade:
      animatePGPP(currentMillis);
      break;
    case WandBatonAnimationState::SinColorPurple:
      animateSCP(currentMillis);
      break;
      case WandBatonAnimationState::None:
      break;  
  }

}

/*
==========================
*/
