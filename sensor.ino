#define PinoTrigger 2  
#define PinoEcho 3      

int timer = 0;
int distance = 0;

void setup ()
{
  pinMode(13, OUTPUT);
  
  pinMode(PinoTrigger,OUTPUT);
  pinMode(PinoEcho,INPUT);
  Serial.begin(9600);
}

void loop()
{
  digitalWrite(13, HIGH);
  
  digitalWrite(PinoTrigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(PinoTrigger,LOW);
  
  timer = pulseIn(PinoEcho, HIGH); 
  distance = timer*0.017175;
  Serial.println(distance); 
  delay(100);
}
