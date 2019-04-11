#include <Adafruit_NeoPixel.h>


int leds=41;
int amountOfLedsFront=31;
Adafruit_NeoPixel ledstrip=Adafruit_NeoPixel(leds,10, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel ledstrip2=Adafruit_NeoPixel(leds,5, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel ledstrip3=Adafruit_NeoPixel(amountOfLedsFront,3, NEO_GRB + NEO_KHZ800);

enum LED_COLOR {Green, Blue, Yellow};
LED_COLOR currentColor;

void setup() {
  // put your setup code here, to run once:
ledstrip.begin();
ledstrip.setBrightness(100);
ledstrip2.begin();
ledstrip2.setBrightness(100);
ledstrip3.begin();
ledstrip3.setBrightness(80);

currentColor = Blue;
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i=0;i<leds;i++)
  {
    if( (i+1) % 4 == 0 )
    {
        if(currentColor == Blue)
        {
          currentColor = Green; 
        }
        else if(currentColor == Green)
        {
          currentColor = Yellow;
        }
        else if(currentColor == Yellow)
        {
          currentColor = Blue;
        }
    }

    if(currentColor == Blue)
    {
      ledstrip.setPixelColor(i,ledstrip.Color(0, 102, 255));
      ledstrip.show();
      ledstrip2.setPixelColor(i,ledstrip2.Color(0, 102, 255));
      ledstrip2.show(); 
      ledstrip3.setPixelColor(i,ledstrip3.Color(0,102, 255));
      ledstrip3.show();
    }
    else if(currentColor == Yellow)
    {
      ledstrip.setPixelColor(i,ledstrip.Color(255, 255, 0));
      ledstrip.show();
      ledstrip2.setPixelColor(i,ledstrip2.Color(255, 255, 0));
      ledstrip2.show(); 
      ledstrip3.setPixelColor(i,ledstrip3.Color(255,255,0));
      ledstrip3.show();
    } 
    else if(currentColor == Green)
    {
      ledstrip.setPixelColor(i,ledstrip.Color(46, 184, 46));
      ledstrip.show();
      ledstrip2.setPixelColor(i,ledstrip2.Color(46, 184, 46));
      ledstrip2.show(); 
      ledstrip3.setPixelColor(i,ledstrip3.Color(46, 184, 46));
      ledstrip3.show();
    }   
  }

  
}
