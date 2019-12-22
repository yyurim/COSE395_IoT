#include <IRremote.h>
/*
  Arduino Christmas Songs
  
  Based on a project and code by Dipto Pratyaksa, updated on 31/3/13

  Modified for Christmas by Joshi, on Dec 17th, 2017.
*/

// NOTES
#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978


// BUZZER : play the music
#define melodyPin 9


// Jingle Bells
int melody[] = {
  NOTE_E5, NOTE_E5, NOTE_E5,
  NOTE_E5, NOTE_E5, NOTE_E5,
  NOTE_E5, NOTE_G5, NOTE_C5, NOTE_D5,
  NOTE_E5,
  NOTE_F5, NOTE_F5, NOTE_F5, NOTE_F5,
  NOTE_F5, NOTE_E5, NOTE_E5, NOTE_E5, NOTE_E5,
  NOTE_E5, NOTE_D5, NOTE_D5, NOTE_E5,
  NOTE_D5, NOTE_G5
};

int tempo[] = {
  8, 8, 4,
  8, 8, 4,
  8, 8, 8, 8,
  2,
  8, 8, 8, 8,
  8, 8, 8, 16, 16,
  8, 8, 8, 8,
  4, 4
};

// We wish you a merry Christmas

int wish_melody[] = {
  NOTE_B3, 
  NOTE_F4, NOTE_F4, NOTE_G4, NOTE_F4, NOTE_E4,
  NOTE_D4, NOTE_D4, NOTE_D4,
  NOTE_G4, NOTE_G4, NOTE_A4, NOTE_G4, NOTE_F4,
  NOTE_E4, NOTE_E4, NOTE_E4,
  NOTE_A4, NOTE_A4, NOTE_B4, NOTE_A4, NOTE_G4,
  NOTE_F4, NOTE_D4, NOTE_B3, NOTE_B3,
  NOTE_D4, NOTE_G4, NOTE_E4,
  NOTE_F4
};

int wish_tempo[] = {
  4,
  4, 8, 8, 8, 8,
  4, 4, 4,
  4, 8, 8, 8, 8,
  4, 4, 4,
  4, 8, 8, 8, 8,
  4, 4, 8, 8,
  4, 4, 4,
  2
};

// Santa Claus is coming to town

int santa_melody[] = {
  NOTE_G4,
  NOTE_E4, NOTE_F4, NOTE_G4, NOTE_G4, NOTE_G4,
  NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, NOTE_C5,
  NOTE_E4, NOTE_F4, NOTE_G4, NOTE_G4, NOTE_G4,
  NOTE_A4, NOTE_G4, NOTE_F4, NOTE_F4,
  NOTE_E4, NOTE_G4, NOTE_C4, NOTE_E4,
  NOTE_D4, NOTE_F4, NOTE_B3,
  NOTE_C4
};

int santa_tempo[] = {
  8,
  8, 8, 4, 4, 4,
  8, 8, 4, 4, 4,
  8, 8, 4, 4, 4,
  8, 8, 4, 2,
  4, 4, 4, 4,
  4, 2, 4,
  1
};


// for IR communication 
int RECV_PIN = 11;

IRrecv irrecv(RECV_PIN);
decode_results results;

// for analog output : brightness
int LEDred = 10;
int LEDgreen = 6;
int LEDblue = 5;

// for digital output : compare the brightness to the max one
int ledRGB = 4;

int brightness = 0;
long temp;
int sensor = A0;
int val;

// continuous play
int keepSinging = 0;

void setup(void) {
  pinMode(sensor, INPUT);
  pinMode(LEDred, OUTPUT);
  pinMode(LEDgreen, OUTPUT);
  pinMode(LEDblue, OUTPUT);
  pinMode(ledRGB, OUTPUT);

  pinMode(melodyPin, OUTPUT);

  // for 1 column 7 segments : location
  pinMode(13, OUTPUT); // g
  pinMode(12, OUTPUT); // e
  pinMode(8, OUTPUT); // d
  pinMode(2, OUTPUT); // a
  pinMode(7, OUTPUT); // b
  pinMode(3, OUTPUT); // c


  Serial.begin(9600);
  
  irrecv.enableIRIn();
  
}

void loop() {
  
  if(irrecv.decode(&results)){
    // for continuous play, save the track number
    keepSinging = results.value;

    
    switch(results.value){
      
      case 0xFF30CF:          
        sing(1);
        Serial.println("sing 1");
        break;
      case 0xFF18E7:
        sing(2);
        Serial.println("sing 2");
        break;
      case 0xFF7A85:
        sing(3);
        Serial.println("sing 3");
        break;
      default:
        break;
        
    }
    
    irrecv.resume();
    
  }
  else{

    // play the previous music
    switch(results.value){
      
      case 0xFF30CF:
        sing(1);
        Serial.println("sing 1");
        break;
      case 0xFF18E7:
        sing(2);
        Serial.println("sing 2");
        break;
      case 0xFF7A85:
        sing(3);
        Serial.println("sing 3");
        break;
      default:
        break;
        
    }
    
    irrecv.resume();

  }
  
  delay(1000);

}

// track number
int song = 0;

void sing(int s) {
  // iterate over the notes of the melody:
  
  digitalWrite(ledRGB, HIGH);

  song = s;
  if (song == 3) {
    // display the track number
    writeSegment(3);                                                
    
    Serial.println(" 'We wish you a Merry Christmas'");
    int size = sizeof(wish_melody) / sizeof(int);
    for (int thisNote = 0; thisNote < size; thisNote++) {

      // to measure the noise, and convert to brightness
      int value = analogRead(sensor);
      Serial.print("NOISE (0 - 1023) : ");
      Serial.println(value);
      brightness = ((float)value/1023)*255;

      // to calculate the note duration, take one second
      // divided by the note type.
      //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
      int noteDuration = 1000 / wish_tempo[thisNote];

      buzz(melodyPin, wish_melody[thisNote], noteDuration);

      Serial.print("BRIGHTNESS (0 - 255) : ");

      // to change color by notes
      switch(thisNote%3){
        case 0:
          analogWrite(LEDred, brightness);
          Serial.println(brightness);
          //digitalWrite(LEDred, HIGH);
          break;
        case 1:
          analogWrite(LEDgreen, brightness);
          Serial.println(brightness);
          //digitalWrite(LEDgreen, HIGH);
          break;
        case 2:
          analogWrite(LEDblue, brightness);
          Serial.println(brightness);
          //digitalWrite(LEDblue, HIGH);
          break;
      }

      // to distinguish the notes, set a minimum time between them.
      // the note's duration + 30% seems to work well:
      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);

      // stop the tone playing:
      buzz(melodyPin, 0, noteDuration);
      
      switch(thisNote%3){
        case 0:
          analogWrite(LEDred, 0);
          break;
        case 1:
          analogWrite(LEDgreen, 0);
          break;
        case 2:
          analogWrite(LEDblue, 0);
          break;
      }

    }
  } else if (song == 2) {
    // display the track number
    writeSegment(2);
    
    Serial.println(" 'Santa Claus is coming to town'");
    int size = sizeof(santa_melody) / sizeof(int);
    for (int thisNote = 0; thisNote < size; thisNote++) {

      // to measure the noise, and convert to brightness
      int value = analogRead(sensor);
      Serial.print("NOISE (0 - 1023) : ");
      Serial.println(value);
      brightness = ((float)value/1023)*255;

      // to calculate the note duration, take one second
      // divided by the note type.
      //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
      int noteDuration = 900 / santa_tempo[thisNote];

      buzz(melodyPin, santa_melody[thisNote], noteDuration);

      Serial.print("BRIGHTNESS (0 - 255) : ");

      // to change color by notes
      switch(thisNote%3){
        case 0:
          analogWrite(LEDred, brightness);
          Serial.println(brightness);
          //digitalWrite(LEDred, HIGH);
          break;
        case 1:
          analogWrite(LEDgreen, brightness);
          Serial.println(brightness);
          //digitalWrite(LEDgreen, HIGH);
          break;
        case 2:
          analogWrite(LEDblue, brightness);
          Serial.println(brightness);
          //digitalWrite(LEDblue, HIGH);
          break;
      }

      // to distinguish the notes, set a minimum time between them.
      // the note's duration + 30% seems to work well:
      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);

      // stop the tone playing:
      buzz(melodyPin, 0, noteDuration);

      switch(thisNote%3){
        case 0:
          analogWrite(LEDred, 0);
          break;
        case 1:
          analogWrite(LEDgreen, 0);
          break;
        case 2:
          analogWrite(LEDblue, 0);
          break;
      }

    }
  } else {
    // display the track number
    writeSegment(1); 

    Serial.println(" 'Jingle Bells'");
    int size = sizeof(melody) / sizeof(int);
    for (int thisNote = 0; thisNote < size; thisNote++) {

      // to measure the noise, and convert to brightness
      int value = analogRead(sensor);
      Serial.print("NOISE (0 - 1023) : ");
      Serial.println(value);
      brightness = ((float)value/1023)*255;

      // to calculate the note duration, take one second
      // divided by the note type.
      //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
      int noteDuration = 1000 / tempo[thisNote];

      buzz(melodyPin, melody[thisNote], noteDuration);

      Serial.print("                                      BRIGHTNESS (0 - 255) : ");

      // to change color by notes
      switch(thisNote%3){
        case 0:
          analogWrite(LEDred, brightness);
          Serial.println(brightness);
          //digitalWrite(LEDred, HIGH);
          break;
        case 1:
          analogWrite(LEDgreen, brightness);
          Serial.println(brightness);
          //digitalWrite(LEDgreen, HIGH);
          break;
        case 2:
          analogWrite(LEDblue, brightness);
          Serial.println(brightness);
          //digitalWrite(LEDblue, HIGH);
          break;
      }


      // to distinguish the notes, set a minimum time between them.
      // the note's duration + 30% seems to work well:
      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);

      // stop the tone playing:
      buzz(melodyPin, 0, noteDuration);

      
      switch(thisNote%3){
        case 0:
          analogWrite(LEDred, 0);
          break;
        case 1:
          analogWrite(LEDgreen, 0);
          break;
        case 2:
          analogWrite(LEDblue, 0);
          break;
      }

    }
  }

  clearSegment();
  digitalWrite(ledRGB, LOW);
  //digitalWrite(ledB, LOW);
}

void buzz(int targetPin, long frequency, long length) {
  
  
  long delayValue = 1000000 / frequency / 2;              // calculate the delay value between transitions
  
  //// 1 second's worth of microseconds, divided by the frequency, then split in half since
  //// there are two phases to each cycle
  long numCycles = frequency * length / 1000; // calculate the number of cycles for proper timing
  
  //// multiply frequency, which is really cycles per second, by the number of seconds to
  //// get the total number of cycles to produce
  for (long i = 0; i < numCycles; i++) {                  // for the calculated length of time...
    digitalWrite(targetPin, HIGH);                        // write the buzzer pin high to push out the diaphram
    delayMicroseconds(delayValue);                        // wait for the calculated delay value
    digitalWrite(targetPin, LOW);                         // write the buzzer pin low to pull back the diaphram
    delayMicroseconds(delayValue);                        // wait again or the calculated delay value
  }

}

// before display the track number
void clearSegment() {       
    digitalWrite(13, LOW);
    digitalWrite(12, LOW);
    digitalWrite(8, LOW);
    digitalWrite(7, LOW);
    digitalWrite(3, LOW);
    digitalWrite(2, LOW);
}

// display the track number
void writeSegment(byte digit){
  clearSegment();
 
  switch(digit){
    case 1:
      digitalWrite(13, LOW);
      digitalWrite(12, LOW);
      digitalWrite(8, LOW);
      digitalWrite(7, HIGH);
      digitalWrite(3, HIGH);
      digitalWrite(2, LOW);
      break;
    case 2:
    digitalWrite(13, HIGH);
      digitalWrite(12, HIGH);
      digitalWrite(8, HIGH);
      digitalWrite(7, HIGH);
      digitalWrite(3, LOW);
      digitalWrite(2, HIGH);
      break;
    case 3:
      digitalWrite(13, HIGH);
      digitalWrite(12, LOW);
      digitalWrite(8, HIGH);
      digitalWrite(7, HIGH);
      digitalWrite(3, HIGH);
      digitalWrite(2, HIGH);
      break;
    default:
      digitalWrite(13, LOW);
      digitalWrite(12, LOW);
      digitalWrite(8, LOW);
      digitalWrite(7, LOW);
      digitalWrite(3, LOW);
      digitalWrite(2, LOW);
    break;   
  }
}
