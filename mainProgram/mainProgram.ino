#include <SoftwareSerial.h>
#include <Servo.h>
#include "Adafruit_VL53L0X.h"


SoftwareSerial mySerial(51, 53); // RX, TX
Servo myservo; 
Adafruit_VL53L0X laser = Adafruit_VL53L0X();


int ind1,ind2,ind3;
String raw_angle,raw_center;
int center,angle;

String dataIn = "";

int run = 0;

int EN1 = 10;
int EN2 = 9;

int LPWM1 = 8;
int RPWM1 = 7;

int LPWM2 = 5;
int RPWM2 = 6;

int kp;
int trial = 0;

unsigned long pt1 = 0;
unsigned long ct1;
unsigned long pt2 = 0;
unsigned long ct2;

int position;
int speedMotor = 0;
//#define Pin_D1_L  8 //lpwm
//#define Pin_D2_L  7 //rpwm
//#define Pin_E_L   10 //pwm enable
////---------------------------------------
////motor 2
//#define Pin_D1_R  5 //lpwm
//#define Pin_D2_R  6 //rpwm
//#define Pin_E_R   9 //pwm enable
////--------------------------------------- 


void setup() {
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  mySerial.begin(9600);
  mySerial.setTimeout(10);

  myservo.attach(9);

  pinMode(EN1, OUTPUT);
  pinMode(EN2, OUTPUT);
  pinMode(LPWM1, OUTPUT);
  pinMode(RPWM1, OUTPUT);
  pinMode(LPWM2, OUTPUT);
  pinMode(RPWM2, OUTPUT);
    if (!laser.begin()) {
    Serial.println(F("Failed to boot VL53L0X"));
    }
  
  Serial.print("oke");
  laser.startRangeContinuous();
}

void loop() {
  ct1 = millis();
  ct2 = millis();

  if(ct1 - pt1 >=100){
    pt1 = ct1;
    VL53L0X_RangingMeasurementData_t measure;
    laser.rangingTest(&measure, false);
    position = measure.RangeMilliMeter;
  }

  dataPy();
   
  
  if(angle >= 80 && angle <= 100){
    Serial.println("oke");
    run = 1;
  }

  switch (run) {
  case 1:
    motor_callibrate(); 
    Serial.println("run 1 oke");
    break;
  case 2:
    motor_run(); 
    if(position <= 500){
      run = 0;
    }
    break;
  case 3:
    myservo.write(90);
    delay(5000);
    run = 4;
    break;
  case 4:
    motor_run();
    run = 0;
    break;
  default:
    motor1('N',0);
    motor2('N',0);
    break;
}


}
