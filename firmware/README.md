# ESP32-C3 Tri-State Toggle

Tenstar ESP32-C3 Super Mini firmware that "presses a button" on GPIO3:
two short LOW pulses (300 ms each, 600 ms apart) every 2.5 minutes, hi-Z otherwise.

## Prerequisites

- [PlatformIO CLI](https://platformio.org/install/cli) (`pio`)
- Board connected via USB (built-in USB-Serial-JTAG shows up as `/dev/ttyACM0`)

## Build

```sh
pio run -d firmware
```

## Flash

```sh
pio run -d firmware -t upload
```

Or build + flash in one go (the default target already builds first — `-t upload` is enough).

## GPIO

The button line is driven by **GPIO3** (`TOGGLE_PIN`) as an open-drain output:

- **Pulse (press):** pin switched to `OUTPUT` and driven `LOW` for `PULSE_MS`
- **Idle (release):** pin switched back to `INPUT` — true hi-Z, no internal
  pull-up/pull-down, never driven high

Because the idle state is hi-Z, an external device can pull the line low at any
time without fighting the ESP32. Add a pull-up resistor if the line needs a
defined high level.

## Configuration

Edit the defines at the top of `src/main.cpp`, then reflash:

```cpp
#define TOGGLE_PIN 3                  // GPIO to drive
#define PERIOD_MS 2.5 * 60 * 1000     // overall cycle time (2.5 minutes)
#define PULSE_MS 300                  // LOW duration per press
#define PULSE_SPACING_MS 600          // start-to-start spacing of the two presses
```
