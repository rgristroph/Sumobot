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
   
   // Turn light off
   digitalWrite(ledPin, 0); 
            

   // Stop
   left_motor.writeMicroseconds(1500);
   right_motor.writeMicroseconds(1500);
   delay(1000);
   
   // Forward
   left_motor.writeMicroseconds(1000);
   right_motor.writeMicroseconds(2000);
   delay(1000);
   
   // Stop
   left_motor.writeMicroseconds(1500);
   right_motor.writeMicroseconds(1500);
   delay(1000);
   
   // Backward
   left_motor.writeMicroseconds(2000);
   right_motor.writeMicroseconds(1000);
   delay(1000);
   
   return;
   
   // Drive forward 1 sec
   left_motor.write(0);
   right_motor.write(180);
   delay(2000);
   
   // Stop 1 sec
   left_motor.write(90);
   right_motor.write(90);
   delay(1000);

   // Backup 1 sec
   left_motor.write(180);
   right_motor.write(0);
   delay(2000);
   
   // Stop 1 sec
   left_motor.write(90);
   right_motor.write(90);
   delay(1000);
   

   return;
   
   // Read the bumb switch
   bump = digitalRead(bump_pin);
   // If we are hitting something, back left for 1/2 sec with the light on
   if (!bump) {
     digitalWrite(ledPin, 1);
     left_motor.write(180);
     right_motor.write(90);
     delay(1000);
   }

 }
