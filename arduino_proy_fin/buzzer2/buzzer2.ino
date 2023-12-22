#include <Tone.h>
#include <Ultrasonic.h>
#define Pecho1 12
#define Ptrig1 13
#define Pecho2 10
#define Ptrig2 11
#define Pecho3 8
#define Ptrig3 9
#define Pecho4 6
#define Ptrig4 7   
#define Pecho5 4
#define Ptrig5 5
#define Pecho6 2
#define Ptrig6 3
#define Pecho7 0
#define Ptrig7 1
#define Pecho8 14
#define Ptrig8 15

#define SONAR_NUM 8
#define MAX_DIST 200
int dur[SONAR_NUM];
Ultrasonic ultrasonic1(Ptrig1, Pecho1);	
Ultrasonic ultrasonic2(Ptrig2, Pecho2);	
Ultrasonic ultrasonic3(Ptrig3, Pecho3);	
Ultrasonic ultrasonic4(Ptrig4, Pecho4);	
Ultrasonic ultrasonic5(Ptrig5, Pecho5);	
Ultrasonic ultrasonic6(Ptrig6, Pecho6);	
Ultrasonic ultrasonic7(Ptrig7, Pecho7);	
Ultrasonic ultrasonic8(Ptrig8, Pecho8);	


int notes[] = { NOTE_C6,
                NOTE_D6,
                NOTE_E6,
                NOTE_F6,
                NOTE_G6,
                NOTE_A6,
                NOTE_B6,
                NOTE_C7 };
Tone notePlayer[8];

//double MedirDist(int, int);
double d1,d2,d3,d4,d5,d6,d7,d8,duracion, distancia;
//int Ns = 4;  // Esto puede cambiar segun la asignacion de pines
//int x = 0;

void setup() {                
  Serial.begin (9600);
  //pines de ultrasonido       // inicializa el puerto seria a 9600 baudios

  //pines buzzer
  notePlayer[0].begin(39);
  notePlayer[1].begin(41);
  notePlayer[2].begin(43);
  notePlayer[3].begin(45);
  notePlayer[4].begin(47);
  notePlayer[5].begin(49);
  notePlayer[6].begin(51);
  notePlayer[7].begin(53);
  }
  
void loop() {
  //MedirDists();
  //primero
  d1 =ultrasonic1.read();
  if(d1 >= 120 || d1 <= 0){
    notePlayer[0].stop();
    }
  else{
    notePlayer[0].play(notes[0]);  
  }
  //segundo
  d2 =ultrasonic2.read();
  if(d2 >= 120 || d2 <= 0){
    notePlayer[1].stop();
    }
  else{
    notePlayer[1].play(notes[1]);  
  }
  //tercero
  d3 =ultrasonic3.read();
  if(d3 >= 120 || d3 <= 0){
    notePlayer[2].stop();
    }
  else{
    notePlayer[2].play(notes[2]);  
  }
  //cuarto
  d4 =ultrasonic4.read();
  if(d4 >= 120 || d4 <= 0){
    notePlayer[3].stop();
    }
  else{
    notePlayer[3].play(notes[3]);  
  }
  //quinto
  d5 =ultrasonic5.read();
  if(d5 >= 120 || d5 <= 0){
    notePlayer[4].stop();
    }
  else{
    notePlayer[4].play(notes[4]);  
  }
  //sexto
  d6 =ultrasonic6.read();
  if(d6 >= 120 || d6 <= 0){
    notePlayer[5].stop();
    }
  else{
    notePlayer[5].play(notes[5]);  
  }
  //septimo
  d7 =ultrasonic7.read();
  if(d7 >= 120 || d7 <= 0){
    notePlayer[6].stop();
    }
  else{
    notePlayer[6].play(notes[6]);  
  }
  //octavo
  d8 =ultrasonic8.read();
  if(d8 >= 120 || d8 <= 0){
    notePlayer[7].stop();
    }
  else{
    notePlayer[7].play(notes[7]);  
  }
}




