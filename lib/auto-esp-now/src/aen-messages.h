#include <Arduino.h>
/*
intr - 1
welc - 2
rqcf - 3
cnfg - 4
data - 5
*/

class AenMessage {
  public:
    AenMessage(uint8_t type);

  private:
    uint8_t  _msg_type;
    char*  _msgtype_code;
};

class AenIntroMessage: public AenMessage {
  const uint8_t messageType = 1;

  public:
    AenIntroMessage();
};

class AenWelcomeMessage: public AenMessage {
  const uint8_t messageType = 2;
  
  public:
    AenWelcomeMessage();
};

class AenWelcomeMessage: public AenMessage {
  const uint8_t messageType = 2;
  
  public:
    AenWelcomeMessage();
};

class AenReqForCfgMessage: public AenMessage {
  const uint8_t messageType = 3;
  
  public:
    AenReqForCfgMessage();
};

class AenConfigMessage: public AenMessage {
  const uint8_t messageType = 4;
  
  public:
    AenConfigMessage();
};

class AenDataMessage: public AenMessage {
  const uint8_t messageType = 5;
  
  public:
    AenDataMessage();
};

