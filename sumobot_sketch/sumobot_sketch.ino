/*
 * Sumobot Jr for ATX Script Kids
 */
 
 #include <Servo.h>
 
 Servo left_motor;
 Servo right_motor;
 
 int bump_pin = 7;
 int ledPin = 13; // built in on the board
 
 void setup() {
   left_motor.attach(9);
   right_motor.attach(10);
   
   pinMode(bump_pin, INPUT_PULLUP);
   pinMode(ledPin,OUTPUT);   
 }
 
 void loop() {
   int bump = 0;
   for (int i = 0; i < 10000; i++) {
     bump = digitalRead(bump_pin);
     if (bump) {
       digitalWrite(ledPin, 1);
     }
     else {
       digitalWrite(ledPin, 0); 
     }
     delay(25);
 /*    digitalWrite(ledPin,1);
     delay(500); 
     digitalWrite(ledPin,0);
     delay(500); */
   }
   
   // Run for 
   left_motor.write(90);
   right_motor.write(90);
   delay(1000);
   
   left_motor.write(0);
   right_motor.write(180);
   delay(1000);
   
   left_motor.write(180);
   right_motor.write(0);
   delay(1000);
   
 }
