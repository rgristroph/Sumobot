#include <IRremote.h>

#include <Adafruit_NeoPixel.h>

int RECV_PIN = 2;
IRsend irsend;
IRrecv irrecv(RECV_PIN);

decode_results results;

const int buttonPin = 2; 
int buttonState = 0;

// Setting up the LEDs.
#define PIN 6
Adafruit_NeoPixel strip = Adafruit_NeoPixel(40, PIN, NEO_GRB + NEO_KHZ800);


int pixels = 0;
int red = 0; 
void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver  		
  irrecv.blink13(true);
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'

}

void loop() {

	if (irrecv.decode(&results)) {
    	  Serial.println(results.value, HEX);
       
     	
    	  if (results.value == 0x4CB3E31C ) {
            strip.setPixelColor(pixels, 100, 0, 0);
    	  }
    	  else {
    	    strip.setPixelColor(pixels, red, 100, 100);
    	  }
    	  pixels++;
    	  if (pixels == 40) {
    	    pixels = 0;
    	    red = red + 50;
    	  } 
    	  strip.setBrightness(100);
    	  strip.show();
    	  Serial.println(red);
    	  irrecv.resume(); // Receive the next value
	}
        
        irsend.send(SONY,0xa8bca, 20);
        irrecv.enableIRIn(); // Re-enable receiver
}

