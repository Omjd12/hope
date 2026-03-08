#ifndef VAL
#define VAL

class MOTOR {
public:
  MOTOR(uint8_t x1, uint8_t x2, uint8_t y1, uint8_t y2) {
    a1 = x1;
    a2 = x2;
    b2 = y2;
    b1 = y1;

    pinMode(a1, OUTPUT);
    pinMode(a2, OUTPUT);
    pinMode(b1, OUTPUT);
    pinMode(b2, OUTPUT);
  }

  void setPWM(uint8_t p1, uint8_t p2) {
    pwm1 = p1;
    pwm2 = p2;

    pinMode(pwm1, OUTPUT);
    pinMode(pwm2, OUTPUT);
  }

  void Run(int16_t value) {
    if (value < 0) {
      anticlockWise();
      pwm = -1 * value;
    } else {
      clockWise();
      pwm = value;
    }
      
    analogWrite(pwm1, pwm);
    analogWrite(pwm2, pwm);
  }
  void stop() {
    digitalWrite(a1, LOW);
    digitalWrite(a2, LOW);
    digitalWrite(b1, LOW);
    digitalWrite(b2, LOW);
  }

private:
  uint8_t a1, a2, b1, b2, pwm1, pwm2, pwm;
  void anticlockWise() {
    digitalWrite(a1, HIGH);
    digitalWrite(a2, LOW);
    digitalWrite(b1, LOW);
    digitalWrite(b2, HIGH);
  }
  void clockWise() {
    digitalWrite(a1, LOW);
    digitalWrite(a2, HIGH);
    digitalWrite(b1, HIGH);
    digitalWrite(b2, LOW);
  }
};
#endif