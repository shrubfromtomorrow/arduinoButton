
#include <SPI.h>
#include <SD.h>
#include <TMRpcm.h>

File myFile;

TMRpcm tmrpcm;

const int chipSelect = 10;
long randNumber;

void setup() {
  pinMode(SS, OUTPUT);
  tmrpcm.speakerPin = 9;

  Serial.begin(9600);
  pinMode(2, INPUT_PULLUP);

  delay(1);


  if (!SD.begin(chipSelect)) {  // see if the card is present and can be initialized:
    Serial.println("SD fail");
    return;  // don't do anything more if not
  }
  tmrpcm.setVolume(5);
  // tmrpcm.play("jupiter.wav");
  // tmrpcm.loop(1);
  tmrpcm.loop(1);
  tmrpcm.play("cat.wav");
}

void loop() {
  // Serial.println(digitalRead(2));
  // delay(1000);
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
    else if (command == 'c') {  //send the letter p over the serial monitor to start playback
      if (tmrpcm.isPlaying() == 1) {
        tmrpcm.stopPlayback();
      }
      tmrpcm.play("cat.wav");
    }
    else if (command == 'p') {  //send the letter p over the serial monitor to start playback
      if (tmrpcm.isPlaying() == 1) {
        tmrpcm.stopPlayback();
      }
      tmrpcm.play("pipe.wav");
      // tmrpcm.loop(1); 
    }
    else if (command == '-') {  //send the letter p over the serial monitor to start playback
      if (tmrpcm.isPlaying() == 1) {
        tmrpcm.pause();
      }
      tmrpcm.volume(0);
      tmrpcm.pause();
    }
    else if (command == '+') {  //send the letter p over the serial monitor to start playback
      if (tmrpcm.isPlaying() == 1) {
        tmrpcm.pause();
      }
      tmrpcm.volume(1);
      tmrpcm.pause();
    }
  }
}
