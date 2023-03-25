void dataPy(){
  
  if(mySerial.available() > 1){
    pt2 = ct2;
    dataIn = "";
    dataIn += mySerial.readString();
    
  ind1 = dataIn.indexOf('#');
  ind2 = dataIn.indexOf('#',ind1 + 1);
  ind3 = dataIn.indexOf('#',ind2 + 1);

  raw_angle = dataIn.substring(ind1 + 1,ind2);
  raw_center = dataIn.substring(ind2 + 1,ind3);

  angle = raw_angle.toInt();
  center = raw_center.toInt();
//
//  if(dataIn.length() >0){
//  Serial.print(angle);
//  Serial.print('|');
//  Serial.println(center);
    
//    Serial.println(dataIn);
  }
  
  if(mySerial.available() < 1){
    if(ct2 - pt2 >= 1000){
    pt2=ct2;
    run = 0;
    dataIn = "";
    center = 0;
    angle = 0;
    

    }  
  }
}



  
  
