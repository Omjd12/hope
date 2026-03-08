#include "DIRN.h"
#include "PID.h"
#include "DRIVE.h"
#include <Wire.h>
#define pass (void)0


//MOTOR m(26, 27, 25, 33);
//PID p(0.1, 0.1, 0.1);
unsigned long now = 0;
unsigned long last_measured = 0;
uint8_t n = 0;
mpu d;
void setup() {
  Serial.begin(115200);
  //m.setPWM(13, 32);
  Wire.begin();
  if (!d.begin()) {
    Serial.print("mpu connected");
    d.caliberate();
    Serial.println("mpu caliberated");
  } else {
    Serial.print("failed to connect mpu");
  }
  delay(10000);
}

void loop() {

  if (now - last_measured > 0000) {

    if (d.check()) {
      d.update();
      last_measured = micros();
    } else {
      Serial.println("failed to update");
    }

    if (d.check()) {
      d.get_dt(now - micros());
      //int16_t output = (int16_t)p.compute(d.getz());
      //m.Run(output);
      Serial.println(d.getz());
      
    } else {
      Serial.println("failed to get value");
      //m.stop();
    }
  } else {
    pass;
  }
  now = micros();
}
