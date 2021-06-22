#define trigPin 12
#define echoPin 13
#define buzzer 11

//Max distance the sensor will make sound (in centimeters)
int maxDistance = 80;
int frequency = 0;


void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}


//Calculates the distance in cm
int calculateDistance() {
  long duration, distance;
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2); 
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); 
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
  return distance; 
}


void loop() {
  int distance = calculateDistance(); 
  
  frequency = (maxDistance * 50);

  Serial.println(frequency);

    if (distance <= 80) { 
      tone(buzzer, frequency);
    }
    
    else {
      noTone(buzzer);
    }
    
    delay(50);
 }
