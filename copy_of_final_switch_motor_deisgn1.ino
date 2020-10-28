int PWM =1;
int countinc =10;
int in1 = 10;
int in2 = 6;
int in3 = 11;
int in4 = 9;
int s1 = 5;
int s2 = 4;
int s3 = 3;
int s4 = 2;
double pot;
void setup(){
	
	pinMode(in1, OUTPUT);
	pinMode(in2, OUTPUT);
	pinMode(in3, OUTPUT);
	pinMode(in4, OUTPUT);
  pinMode(pot, INPUT);
  pinMode(s1,INPUT_PULLUP);
    pinMode(s2,INPUT_PULLUP); 
    pinMode(s3,INPUT_PULLUP);
  pinMode(s4,INPUT_PULLUP);
  Serial.begin(9600);
    digitalWrite(in1, LOW);
	digitalWrite(in2, LOW);
	digitalWrite(in3, LOW);
	digitalWrite(in4, LOW);
	
}

void loop() {
  pot = analogRead(A0);
   pot = map(pot, 0, 1023, 0, 255);
  
  if(digitalRead(s1)==0){
	forward();
    delay(1000);}
  if(digitalRead(s2)==0){
    backwards();
    delay(1000);}
   if(digitalRead(s3)==0){
    backwardforward();
    delay(1000);}
  if(digitalRead(s4)==0){
    forwardbackward();
    delay(1000);}
  
  else {
    
    digitalWrite(in1, LOW);
	digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
	digitalWrite(in4, LOW);
  }
}

void forward() {
 
  PWM +=countinc;
  analogWrite(in1, PWM);
  analogWrite(in3, PWM);
	delay(2000);	
	
	digitalWrite(in1, LOW);
	digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
	digitalWrite(in4, LOW);
}

void backwards() {
	PWM +=countinc;
	digitalWrite(in1, LOW);
	analogWrite(in2, PWM);
   digitalWrite(in3, LOW);
	analogWrite(in4, PWM);
  
	delay(2000);
	
	digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
	digitalWrite(in3, LOW);
	digitalWrite(in4, LOW);
}
void backwardforward(){
  PWM +=countinc;
   analogWrite(in1, PWM);
	digitalWrite(in2, LOW);
   digitalWrite(in3, LOW);
	analogWrite(in4, PWM);
  
	delay(2000);
	
	digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
	digitalWrite(in3, LOW);
	digitalWrite(in4, LOW);

}
void forwardbackward(){
  PWM +=countinc;
  digitalWrite(in1, LOW);
	analogWrite(in2, PWM);
   analogWrite(in3, PWM);
	digitalWrite(in4, LOW);
  
	delay(2000);
	
	digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
	digitalWrite(in3, LOW);
	digitalWrite(in4, LOW);

}