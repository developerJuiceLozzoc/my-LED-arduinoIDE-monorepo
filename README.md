# Microcontrollers with Arduino IDE

A repository to organize and document all the microcontrollers flashed and programmed using the Arduino IDE.

## Table of Contents

1. [Features](#features)
2. [Getting Started](#getting-started)
3. [Installation](#installation)
4. [Usage](#usage)
5. [Supported Microcontrollers](#supported-microcontrollers)
6. [Framework and Configuration](#framework-and-configuration)
7. [Class Encapsulation and Extensions](#class-encapsulation-and-extensions)
8. [Contributing](#contributing)
9. [License](#license)

## Features

- Collection of microcontroller-specific code and configurations.
- Detailed examples for different microcontroller models.
- Troubleshooting guides and tips for using the Arduino IDE.

## Getting Started

Instructions to help users set up their environment and get started with flashing microcontrollers.

### Prerequisites

- Arduino IDE installed on your system.
- Necessary drivers for your microcontroller (e.g., CH340, CP210x).

### Installation

Provide a step-by-step guide on how to set up the repository and tools.

```bash
# Clone the repository
git clone git@github.com:developerJuiceLozzoc/my-LED-arduinoIDE-monorepo.git
cd microcontrollers-arduino
```

## Usage

Explain how to use the repository for flashing and programming microcontrollers.

```bash
# Open a project folder in Arduino IDE
# Select the correct board and port
# Upload the code to your microcontroller
```

## Supported Microcontrollers

- Arduino Nano
- ESP32
- SEEED nRF52840

Add more microcontrollers as they are supported.

## Framework and Configuration

This repository uses the INO framework to deploy C and C++ code to various microcontroller boards through the Arduino IDE. It includes:

- **Platform-specific Configurations:** Most platforms support the `FastLED` library, but smaller microcontrollers may require `Adafruit_NeoPixel.h`.
- **PlatformHelpers:** This configuration is defined in `PlatformHelpers.h/cpp`, where platform-agnostic utilities such as `Set Pixel` are implemented.

### Example: Set Pixel Function

```cpp
void setPixel(PlatformAgnosticPixel pixel, uint16_t index, ClusterNameEnum cluster) {
  #if defined(NeoPixelRequired)
    if(cluster == ClusterNameEnum::largeCluster) {
      ledCluster1.setPixelColor(index, ledCluster1.Color(pixel.r, pixel.g, pixel.b));
    } else {
      ledCluster2.setPixelColor(index, ledCluster2.Color(pixel.r, pixel.g, pixel.b));
    }
  #elif defined(FastLEDEnabled)
    if(cluster == ClusterNameEnum::largeCluster) {
      ledCluster1[index] = CRGB(pixel.r, pixel.g, pixel.b);
    } else {
      ledCluster2[index] = CRGB(pixel.r, pixel.g, pixel.b);
    }
  #endif
}
```

## Class Encapsulation and Extensions

To enhance extensibility and encapsulation, this repository includes class objects for modular programming. These classes expose public methods that can be accessed in the `loop` method provided by the INO framework.

### Example: RabbitTurtleChaseService

```cpp
#ifndef CHASESERVICE_H
#define CHASESERVICE_H

void homeWindowStripLoop();

class RabbitTurtleChaseService {
public:
    void updatePositions();
    RabbitTurtleChaseService();
    bool hasCaughtRabbit();
    void resetRace();

private:
    void printTurtle();
    void printRabbit();
    void updateTurtlePosition(unsigned long time);
    void updateRabbitPosition(unsigned long time);
    double turtleVelocity;
    double rabbitVelocity;
    int turtlePosition;
    double rabbitPosition;
    unsigned long rabbitAccelerationTimer;
    unsigned long startTime;
    void updateRabbitVelocity();
    unsigned long millisOffset;
};

#endif // CHASESERVICE_H
```

This approach allows for structured and reusable code, supporting encapsulated logic for specific functionalities. Public methods like `updatePositions` and `printTurtle` can be called within the Arduino `loop` function to integrate with broader workflows.

## Contributing

Contributions are welcome! If you want to contribute:

1. Fork the repository.
2. Create a new branch for your changes.
3. Submit a pull request with detailed notes about your updates.

## License

This project is licensed under the MIT License. See the LICENSE file for details.
