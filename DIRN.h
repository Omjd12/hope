#ifndef DRN_H
#define DRN_H

#include <MPU6050.h>
#include <I2Cdev.h>

class mpu{
  public:
  bool begin(){
    mpu.initialize();
    mpu.setFullScaleGyroRange(MPU6050_GYRO_FS_500);
    return mpu.testConnection();
  }

  void update(){
    int16_t ax, ay, az, gx, gy, gz;
    mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
    gyroz = (float)gz/65.5;
    yawRate = gyroz - offset;
    yaw += yawRate*(dt/1000000);
  }

  float getz(){
    return (yaw/1000000);
  }

  void get_dt(unsigned long t){
    dt = t;
  }

  void caliberate(){
    float sum = 0.0;
    for(int i=0; i<=sample; i++){
      int16_t gx, gy, gz;
      mpu.getRotation(&gx, &gy, &gz);
      sum += (float)gz/65.5;
      delay(1);
    }
    offset = sum/sample;
  }


  bool check(){
    if(mpu.testConnection()){
      return false;
    }
    else{ return true;}
  }

  private:
  MPU6050 mpu;
  unsigned long dt = 0;
  float gyroz;
  float offset = 0.0;
  int sample =2000;
  float yawRate = 0.0; // its the instentanious angular velocity
  float yaw = 0.0;

};

#endif 