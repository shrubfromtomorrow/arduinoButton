/*
  SD card read/write
 
 This example shows how to read and write data to and from an SD card file 	
 The circuit:
 * SD card attached to SPI bus as follows:
 ** UNO:  MOSI - pin 11, MISO - pin 12, CLK - pin 13, CS - pin 4 (CS pin can be changed)
  and pin #10 (SS) must be an output
 ** Mega:  MOSI - pin 51, MISO - pin 50, CLK - pin 52, CS - pin 4 (CS pin can be changed)
  and pin #52 (SS) must be an output
 ** Leonardo: Connect to hardware SPI via the ICSP header

 
 created   Nov 2010  by David A. Mellis
 modified 9 Apr 2012  by Tom Igoe
 
 This example code is in the public domain.
 	 
 */

#include <SPI.h>
#include <SD.h>
#include <TMRpcm.h>

File myFile;

TMRpcm tmrpcm;

// change this to match your SD shield or module;
//     Arduino Ethernet shield: pin 4
//     Adafruit SD shields and modules: pin 10
//     Sparkfun SD shield: pin 8
const int chipSelect = 10;
long randNumber;

void setup() {
  pinMode(SS, OUTPUT);
  tmrpcm.speakerPin = 9;

  Serial.begin(9600);

  delay(1);


  if (!SD.begin(chipSelect)) {  // see if the card is present and can be initialized:
    Serial.println("SD fail");
    return;  // don't do anything more if not
  }
  tmrpcm.setVolume(2);
  // tmrpcm.play("doom.wav");
}

void loop() {
  if (Serial.available()) {
    char command = Serial.read();
    if (command == 's') {  //send the letter p over the serial monitor to start playback
      if (tmrpcm.isPlaying() == 1) {
        tmrpcm.stopPlayback();
      }
      tmrpcm.play("synth.wav");
    }
    else if (command == 'd') {  //send the letter p over the serial monitor to start playback
      if (tmrpcm.isPlaying() == 1) {
        tmrpcm.stopPlayback();
      }
      tmrpcm.play("doom.wav");
    }
    else if (command == 'j') {  //send the letter p over the serial monitor to start playback
      if (tmrpcm.isPlaying() == 1) {
        tmrpcm.stopPlayback();
      }
      tmrpcm.play("jupiter.wav");
    }
  }
}
