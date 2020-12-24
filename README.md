# Reactive LED Light Strip
Using an individually-addressable LED strip and an Arduino to mimic the light coming from a Windows computers screen. Place the led strip on the back of your screen to light up the wall behind it with accurate colors!
Using the GetPixel method built into windows, we are able to sample a few pixels from the screen and then replicate those pixel colors on our strip of lights.  Right now it samples 4 pixels near the top of the screen and splits up the LED strip into 4 sections, imitating the pixels sampled.

Current Files include:
  SampleScreen.cc  -  c++ file to be compiled and ran on the windows PC
  ReactiveLEDArduino.ino  -  Upload this to your Arduino
  ReactiveLED.exe  -  Executable that is ran on the windows PC

Dependencies: 
  FastLED  -  One of the LED strip libraries for accessing the indiviudally-addressable strip of lights (https://github.com/FastLED/FastLED)
  ArduSerial  -  Used for serial communication to Arduino (https://github.com/PowerBroker2/ArduSerial)
  
Very barebones right now.  In order for this to work without changing anything is to use data pin 7 on the arduino with 60 LED's on the strip.
And the Arduino has to be plugged into COM4 of your PC.
I intend to make this generally usable soon.
Also note that this runs pretty slow. It is only sampling 4 pixels from your screen, any more and it would be too slow to be considered reactive lights. I might try the bitmapping method instead of GetPixel.
