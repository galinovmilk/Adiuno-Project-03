const int sensorPin=A0;
const float baselineTemp=68.0;

void setup() {
  Serial.begin(9600); // open a serial port
  for(int pinNumber = 2; pinNumber<5; pinNumber++){
    pinMode(pinNumber, OUTPUT);
    digitalWrite(pinNumber, LOW);
  }
}

void loop() {
  int sensorVal = analogRead(sensorPin);
  Serial.print ("Sensor Value: ");
  Serial.print (sensorVal);
  //convert the ADC reading to the voltage
  float voltage = (sensorVal/1024.0)*5.0;
  Serial.print(" , Volts: ");
  Serial.print(voltage);
  Serial.print(" , degrees F: ");
  //convert the voltage to temperature in degrees
  float temperature = ((voltage - 0.5)*100)*1.8+32;
  Serial.println(temperature);
  if(temperature < baselineTemp+3.6) {
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  }else if (temperature >= baselineTemp+3.6 && temperature < baselineTemp+7.2){
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  }else if (temperature >= baselineTemp+7.2 && temperature < baselineTemp+10.8){
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
  }else if (temperature >=  baselineTemp+10.8){
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
  }
  delay(2);
}
