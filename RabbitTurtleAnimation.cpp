#include "FastLEDHelpers.h"

// fileprivate function
void printDots(int xDots, int here, PlatformAgnosticPixel color) {
  const PlatformAgnosticPixel black = PlatformAgnosticPixel(0,0,0);
  for(int i=0; i< CLUSTER_1_COUNT; i++) {
      setPixel(black,i,ClusterNameEnum::largeCluster);
  }
  for(uint8_t offset = 0; offset < xDots; offset++) {
      if(here - offset < 0) {
      setPixel(color, here - offset + CLUSTER_1_COUNT,ClusterNameEnum::largeCluster);
      } else {
        setPixel(color, here - offset,ClusterNameEnum::largeCluster);
      }
  }
   Show();
}

// Constructor to initialize the animals
RabbitTurtleChaseService::RabbitTurtleChaseService() {
    rabbitVelocity = double(CLUSTER_1_COUNT) / 5000.0;
    rabbitAccelerationTimer = 0;
    turtleVelocity = double(CLUSTER_1_COUNT) / 10000.0;
    rabbitPosition = 1;
    turtlePosition = 0;
    startTime = 0;
    millisOffset = 0;
}

void RabbitTurtleChaseService::printTurtle() {
 PlatformAgnosticPixel constructionOrange = PlatformAgnosticPixel(255,79,0);
  const uint8_t dotCount = 3;
  const PlatformAgnosticPixel black = PlatformAgnosticPixel(0,0,0);
  printDots(dotCount, turtlePosition, constructionOrange);
}
void RabbitTurtleChaseService::printRabbit() {
  const PlatformAgnosticPixel purpleRabbit = PlatformAgnosticPixel(128, 0, 128);
  const uint8_t dotCount = 8;
  printDots(dotCount, (int)rabbitPosition % CLUSTER_1_COUNT, purpleRabbit);
}

void RabbitTurtleChaseService::updateRabbitVelocity() {
    const long currentTime = millis();
    // 10 times a second we call this.
   if (currentTime - rabbitAccelerationTimer > 1500 && rabbitVelocity > double(CLUSTER_1_COUNT) / 20000.0) {
    rabbitAccelerationTimer = currentTime;
    rabbitVelocity *= 0.90;
   }
}

void RabbitTurtleChaseService::updatePositions() {
    unsigned long now = millis() - millisOffset;
    updateTurtlePosition(now);
    updateRabbitPosition(now);
    startTime = now;
    updateRabbitVelocity();
    printRabbit();
    printTurtle();
}


/*
fixed velocity entire race.
*/
void RabbitTurtleChaseService::updateTurtlePosition(unsigned long time) { 
    double time2 = (double) time;
     int new_position = (int)(turtleVelocity * time2) % CLUSTER_1_COUNT;
    turtlePosition = new_position;

}

/*
Update Rabbit position has be implmented as adding a small chuck of distance 
in a time interval because its velocity changes over time.
i could use 0.5*a*t*t but eventually the velocity stopps accelerating.
*/
void RabbitTurtleChaseService::updateRabbitPosition(unsigned long time) {
    unsigned long elapsedTime = time - startTime;
    rabbitPosition += rabbitVelocity * elapsedTime;
}


bool RabbitTurtleChaseService::hasCaughtRabbit() {
  return turtlePosition == (int)rabbitPosition % CLUSTER_1_COUNT;
}

void RabbitTurtleChaseService::resetRace() {
  rabbitVelocity = double(CLUSTER_1_COUNT) / 5000.0;
  millisOffset = millis();
  turtlePosition = 0;
  rabbitPosition = 1;
  startTime = 0;
}

void homeWindowStripLoop() {
    const PlatformAgnosticPixel black = PlatformAgnosticPixel(0,0,0);

  const PlatformAgnosticPixel red = PlatformAgnosticPixel(200,0,0);

  static RabbitTurtleChaseService animator = RabbitTurtleChaseService();

  if (animator.hasCaughtRabbit()) {
    delay(500);
     for(int i=0; i< CLUSTER_1_COUNT; i++) {
      if(i%5 == 0) {
        setPixel(red,i,ClusterNameEnum::largeCluster);
      } else {
        setPixel(black,i,ClusterNameEnum::largeCluster);
      }
     }
     Show();
     delay(1000);
     animator.resetRace();
  } else {
    animator.updatePositions();
  }


}