#define PinoTrigger 2  
#define PinoEcho 3      

int timer = 0;
int distance = 0;

void setup ()
{
  // configuring led light
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);

  // configuring ultrasonic sensor
  pinMode(PinoTrigger,OUTPUT);
  pinMode(PinoEcho,INPUT);
  Serial.begin(9600);
}

void loop()
{
  // setting initial state of led lights
  digitalWrite(13, HIGH); // green
  digitalWrite(12, LOW); // red

  // configuring ultrasonic wave
  digitalWrite(PinoTrigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(PinoTrigger,LOW);
  
  timer = pulseIn(PinoEcho, HIGH); 
  // turning inches into centimeters
  distance = timer*0.017175;
  Serial.println(distance); 

  // integrating led light with ultrasonic sensor
  if (distance < 20) {
    digitalWrite(13, LOW);
    digitalWrite(12, HIGH);
  }
  
  delay(100);
}
