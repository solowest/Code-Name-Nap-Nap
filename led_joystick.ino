 int ledPin = 13;
 int joyPin1 = 0;                 // slider variable connecetd to analog pin 0
 int joyPin2 = 1;                 // slider variable connecetd to analog pin 1
 int value1 = 0;                  // variable to read the value from the analog pin 0
 int value2 = 0;                  // variable to read the value from the analog pin 1
 int value1_2 = 0;
 int value2_2 = 0;

 void setup() {
  pinMode(ledPin, OUTPUT);              // initializes digital pins 0 to 7 as outputs
  Serial.begin(9600);
 }

 int treatValue(int data) {
  return (data * 9 / 1024) + 48;
 }

 void loop() {
  // reads the value of the variable resistor 
  value1 = analogRead(joyPin1);  
  value2 = analogRead(joyPin2); 

  // this small pause is needed between reading
  // analog pins, otherwise we get the same value twice
  delay(200);             
  // reads the value of the variable resistor 
  value1_2 = analogRead(joyPin1);
  value2_2 = analogRead(joyPin2);

  Serial.print('J');
  Serial.print(treatValue(value1_2));
  Serial.println(treatValue(value2_2)); 
  
  if(treatValue(value1_2) != 52 || treatValue(value2_2) != 52) {
    digitalWrite(ledPin, HIGH);
  }           
  else{
    digitalWrite(ledPin, LOW);
  }

 }
