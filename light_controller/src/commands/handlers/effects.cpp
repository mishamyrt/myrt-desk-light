#include "Arduino.h"
#include "../../animator/effects.h"

#define EFFECT_COMMAND_RAINBOW 1

void handle_start_effect(uint8_t *message, uint8_t message_length) {
  switch (message[1]) {
  case EFFECT_COMMAND_RAINBOW:
    Animator.startEffect(Rainbow);
    break;
  }
}