#include "aen-messages.h"

AenMessage::AenMessage(uint8_t type) {
  _msg_type = type;
}

AenIntroMessage::AenIntroMessage() : AenMessage(messageType) {}

AenWelcomeMessage::AenWelcomeMessage() : AenMessage(messageType) {}

AenReqForCfgMessage::AenReqForCfgMessage() : AenMessage(messageType) {}

AenConfigMessage::AenConfigMessage() : AenMessage(messageType) {}

AenDataMessage::AenDataMessage() : AenMessage(messageType) {}

