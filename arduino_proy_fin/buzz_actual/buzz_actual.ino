#include <Tone.h>

#define Ptrig1 52
#define Pecho1 50

#define Ptrig2 48
#define Pecho2 46

#define Ptrig3 44
#define Pecho3 42

#define Ptrig4 40   
#define Pecho4 38  

// #define Ptrig5 36
// #define Pecho5 34

// #define Ptrig6 32
// #define Pecho6 30

// #define Ptrig7 28
// #define Pecho7 26

// #define Ptrig8 24
// #define Pecho8 22


int notes[] = { NOTE_C6,
                NOTE_D6,
                NOTE_E6,
                NOTE_F6,
                NOTE_G6,
                NOTE_A6,
                NOTE_B6,
                NOTE_C7 };
Tone notePlayer[4];

//double MedirDist(int, int);
double d1,d2,d3,d4,duracion, distancia;
//int Ns = 4;  // Esto puede cambiar segun la asignacion de pines ,d5,d6,d7,d8
//int x = 0;

void setup() {                
  Serial.begin (9600);
  //pines de ultrasonido       // inicializa el puerto seria a 9600 baudios
  pinMode(Pecho1, INPUT);     // define el pin 6 como entrada (echo)
  pinMode(Ptrig1, OUTPUT); // define el pin 7 como salida  (triger)
  
  pinMode(Pecho2, INPUT);     
  pinMode(Ptrig2, OUTPUT);
  
  pinMode(Pecho3, INPUT);
  pinMode(Ptrig3, OUTPUT);
  
  pinMode(Pecho4, INPUT);     
  pinMode(Ptrig4, OUTPUT);

  // pinMode(Pecho5, INPUT);     
  // pinMode(Ptrig5, OUTPUT);

  // pinMode(Pecho6, INPUT);     
  // pinMode(Ptrig6, OUTPUT);

  // pinMode(Pecho7, INPUT);     
  // pinMode(Ptrig7, OUTPUT);

  // pinMode(Pecho8, INPUT);     
  // pinMode(Ptrig8, OUTPUT);

  //pines buzzer
  notePlayer[0].begin(53);
  notePlayer[1].begin(49);
  notePlayer[2].begin(45);
  notePlayer[3].begin(41);
  // notePlayer[4].begin(37);
  // notePlayer[5].begin(33);
  // notePlayer[6].begin(29);
  // notePlayer[7].begin(25);
  }
  
void loop() {
  delay(1);
  //MedirDists();
  //primero
  d1 =MedirDist(Ptrig1,Pecho1);
  if(d1 >= 120 || d1 <= 0){
    notePlayer[0].stop();
    }
  else{
    notePlayer[0].play(notes[0]);  
  }
  //segundo
  d2=MedirDist(Ptrig2,Pecho2);
  if(d2 >= 120 || d2 <= 0){
    notePlayer[1].stop();
    }
  else{
    notePlayer[1].play(notes[1]);  
  }
  //tercero
  d3=MedirDist(Ptrig3,Pecho3);
  if(d3 >= 120 || d3 <= 0){
    notePlayer[2].stop();
    }
  else{
    notePlayer[2].play(notes[2]);  
  }
  //cuarto
  d4=MedirDist(Ptrig4,Pecho4);
  if(d4 >= 120 || d4 <= 0){
    notePlayer[3].stop();
    }
  else{
    notePlayer[3].play(notes[3]);  
  }
  //quinto
  // d5=MedirDist(Ptrig5,Pecho5);
  // if(d5 >= 120 || d5 <= 0){
  //   notePlayer[4].stop();
  //   }
  // else{
  //   notePlayer[4].play(notes[4]);  
  // }
  // //sexto
  // d6=MedirDist(Ptrig6,Pecho6);
  // if(d6 >= 120 || d6 <= 0){
  //   notePlayer[5].stop();
  //   }
  // else{
  //   notePlayer[5].play(notes[5]);  
  // }
  // //septimo
  // d7=MedirDist(Ptrig7,Pecho7);
  // if(d7 >= 120 || d7 <= 0){
  //   notePlayer[6].stop();
  //   }
  // else{
  //   notePlayer[6].play(notes[6]);  
  // }
  // //octavo
  // d8=MedirDist(Ptrig8,Pecho8);
  // if(d8 >= 120 || d8 <= 0){
  //   notePlayer[7].stop();
  //   }
  // else{
  //   notePlayer[7].play(notes[7]);  
  // }
}

double MedirDist(int sensorTrig, int sensorEcho)
{
  digitalWrite(sensorTrig, LOW);
  delayMicroseconds(2);
  digitalWrite(sensorTrig, HIGH);   // genera el pulso de triger por 10us
  delayMicroseconds(5);
  digitalWrite(sensorTrig, LOW);
  
  duracion = pulseIn(sensorEcho, HIGH);
  distancia = (duracion/2) / 29;   
  return distancia;
}



