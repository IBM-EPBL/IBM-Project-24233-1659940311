const int gas = 0;
int MQ2pin = A0;
int led = 13;                // the pin that the LED is atteched to
int sensor = 2;              // the pin that the sensor is atteched to
int state = LOW;             // by default, no motion detected
int val = 0; 


void setup() {
  Serial.begin(96000);
  pinMode(led, OUTPUT);      // initalize LED as an output
  pinMode(sensor, INPUT);    // initialize sensor as an input
  Serial.begin(9600);   
}

void loop() {
  val = digitalRead(sensor);   // read sensor value
  if (val == HIGH) {           // check if the sensor is HIGH
    digitalWrite(led, HIGH);   // turn LED ON
    delay(500);                // delay 100 milliseconds 
    
    if (state == LOW) {
      Serial.println("Motion detected!"); 
      state = HIGH;       // update variable state to HIGH
    }
  } 
  else {
      digitalWrite(led, LOW); // turn LED OFF
      delay(500);             // delay 200 milliseconds 
      
      if (state == HIGH){
        Serial.println("Motion stopped!");
        state = LOW;       // update variable state to LOW
    }
  } 
  
  float sensorValue,MQ2pin;  //Gas sensor
  sensorValue = analogRead(MQ2pin);
  if(sensorValue >= 470){
    digitalWrite(11,HIGH);
     digitalWrite(9,HIGH);
    Serial.print(sensorValue);
    Serial.println(" !!ALERT!!");
    
  
  }
  else{
  	digitalWrite(11,LOW);
    digitalWrite(9,LOW);
    Serial.println("Sensor Value: ");
    Serial.println(sensorValue);
  } 
  delay(1000);
}
	float getsensorValue(int pin){
  	return (analogRead(pin));
    }

       
