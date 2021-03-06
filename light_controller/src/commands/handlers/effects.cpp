#include "Arduino.h"
#include "../../animator/effects.h"

#define EFFECT_COMMAND_RAINBOW 1
#define EFFECT_COMMAND_SUNSET 2

bool handle_start_effect(uint8_t *message, uint8_t message_length) {
  switch (message[1]) {
    case EFFECT_COMMAND_RAINBOW:
      Animator.startEffect(Rainbow);
      return true;
    case EFFECT_COMMAND_SUNSET:
      Animator.startEffect(Sunset);
      return true;
  }
  return false;
}
