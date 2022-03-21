#pragma once

#include "Arduino.h"
#include "FastLED.h"
#include "common.h"
#include "../../light/light.h"

#define ZONES_MAX_COUNT 24
#define CROSSFADE_STEP_COUNT 12
const float CROSSFADE_STEP = 1.0 / CROSSFADE_STEP_COUNT;

typedef struct Zone {
  uint8_t from;
  uint8_t to;
  CRGB target_color;
  CRGB previous_color;
  CRGB color;
};

class CrossfadeEffect: public Effect {
public:
  void draw() {
    progress = CROSSFADE_STEP * (float)step;
    for (int i = 0; i < zones_count; i++) {
      drawZone(i, progress);
    }
    if (Light.brightness != target_brightness) {
      Light.brightness = blend_values(start_brightness, target_brightness, progress);
    }
  }

  void prepare () {
    step = 1;
  }

  uint8_t stepCount() {
    return CROSSFADE_STEP_COUNT;
  }

  uint8_t stepDelay() {
    return 4;
  }

  uint8_t target_brightness;
  uint8_t start_brightness;
  uint8_t zones_count;
  Zone zones[ZONES_MAX_COUNT];
  bool is_zones_inverted;

private:
  void drawZone(uint8_t zone_idx, float ratio) {
    if (zones[zone_idx].target_color == zones[zone_idx].color) {
      return;
    }
    zones[zone_idx].color = blend_rgb(
      zones[zone_idx].previous_color,
      zones[zone_idx].target_color,
      ratio
    );
    Light.setLEDs(
      zones[zone_idx].color,
      zones[zone_idx].from,
      zones[zone_idx].to
    );
  };
};
