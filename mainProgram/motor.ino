void motor_callibrate(){
  kp = center * 1;
  kp = abs(kp);
  kp = min(max(kp,0), 10);
  Serial.println(kp);
  
  if(center > 0 && center < 100){
    motor1('F',kp);
    motor2('B',kp);
  }else if(center > 100){
    motor1('F',50);
    motor2('B',50);
  }
  
  if(center < 0 && center > -100){
    motor1('B',kp);
    motor2('F',kp);
  }else if(center < -100){
    motor1('B',50);
    motor2('F',50);
  }
  
  if(center == 0){
    motor1('N',0);
    motor2('N',0);
    delay(200);
    run = 2;
    
}
}

void motor_run(char stepgo){
  if(stepgo == '
  if(position >1000){
    speedMotor = 255;
  }else if(position <1000){
    speedMotor = map(speedMotor, 400, 1000,5, 255);
  }
  
  if(center >= 3 && center <100){
    motor1('F',speedMotor);
    motor2('F',speedMotor - 100);
  }else if(center >= 100){
    motor1('F',speedMotor);
    motor2('F',0);
  }
  if(center <=-3 && center > -100){
    motor1('F',speedMotor - 100);
    motor2('F',speedMotor);
  }else if(center <= -100){
    motor1('F',0);
    motor2('F',speedMotor);
  }
    
  if(center >= -3 && center <= 3){
    motor1('F',speedMotor);
    motor2('F',speedMotor);
  }  
}

void motor1(char dir,int spd){
  if(dir == 'N'){
    analogWrite(EN1, 0);
    digitalWrite(LPWM1,LOW);
    digitalWrite(RPWM1,LOW); 


  } 
  if(dir == 'F'){
    analogWrite(EN1, spd);
    digitalWrite(LPWM1,LOW);
    digitalWrite(RPWM1,HIGH); 

  }
  if(dir == 'B'){
    analogWrite(EN1, spd);
    digitalWrite(LPWM1,HIGH);
    digitalWrite(RPWM1,LOW); 
    Serial.println("B");
  }
}

void motor2(char dir,int spd){
  if(dir == 'N'){
    analogWrite(EN2, 0);
    digitalWrite(LPWM2,LOW);
    digitalWrite(RPWM2,LOW); 

  } 
  if(dir == 'F'){
    analogWrite(EN2, spd);
    digitalWrite(LPWM2,LOW);
    digitalWrite(RPWM2,HIGH); 
  }
  if(dir == 'B'){
    analogWrite(EN2, spd);
    digitalWrite(LPWM2,HIGH);
    digitalWrite(RPWM2,LOW); 
  }
}
