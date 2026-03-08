#ifndef PI_D
#define PI_D

class PID{
public:
  float kp, ki, kd;

  PID(float p, float i, float d){
    setConstant(p, i, d);
    reset();
  }

  void setConstant(float p, float i, float d) {
    if (p < 0 || i < 0 || d < 0) {
      kp = 0.0;
      ki = 0.0;
      kd = 0.0;
    } else {
      kp = p;
      ki = i;
      kd = d;
    }
  }

   float compute(float input, float target = 0.0){
    error = target - input;
    derivative = error-previousError;
    integral += error;

    float value = kp * error + ki * integral + kd * derivative;
    return value;
  }

  void reset(){
    error = integral = derivative = previousError = 0;
  }




private:
  float error, derivative, integral, previousError;
};

#endif