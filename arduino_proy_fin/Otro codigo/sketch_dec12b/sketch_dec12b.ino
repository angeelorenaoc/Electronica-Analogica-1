#include <Tone.h>

#define Ptrig1 52
#define Pecho1 50

#define Ptrig2 48
#define Pecho2 46

#define Ptrig3 44
#define Pecho3 42

#define Ptrig4 40   
#define Pecho4 38  

#define Ptrig5 36
#define Pecho5 34

#define Ptrig6 32
#define Pecho6 30

#define Ptrig7 28
#define Pecho7 26

#define Ptrig8 24
#define Pecho8 22  

#define Buzzer1 53
#define Buzzer2 49
#define Buzzer3 45
#define Buzzer4 41
#define Buzzer5 37
#define Buzzer6 33
#define Buzzer7 29
#define Buzzer8 25

double MedirDist(int, int);
double d, duracion, distancia;
int Ns = 8;  // Esto puede cambiar segun la asignacion de pines
int x=0;
void setup() {                
  Serial.begin (9600);       // inicializa el puerto seria a 9600 baudios
  pinMode(Pecho1, INPUT);     // define el pin 6 como entrada (echo)
  pinMode(Ptrig1, OUTPUT); // define el pin 7 como salida  (triger)
  
  pinMode(Pecho2, INPUT);     
  pinMode(Ptrig2, OUTPUT);
  
  pinMode(Pecho3, INPUT);
  pinMode(Ptrig3, OUTPUT);
  
  pinMode(Pecho4, INPUT);     
  pinMode(Ptrig4, OUTPUT);

  pinMode(Pecho5, INPUT);     
  pinMode(Ptrig5, OUTPUT);

  pinMode(Pecho6, INPUT);     
  pinMode(Ptrig6, OUTPUT);

  pinMode(Pecho7, INPUT);     
  pinMode(Ptrig7, OUTPUT);

  pinMode(Pecho8, INPUT);     
  pinMode(Ptrig8, OUTPUT);
  }
  
void loop() {
  do{
    d = MedirDist(52-4*x,50-4*x);
    Serial.print(x);
    if (d >= 130 || d <= 0){  // si la distancia es mayor a 120cm o menor a 0cm 
    	Serial.println("---");                  // no mide nada
  	}
    else {
    	Serial.print(d);           // envia el valor de la distancia por el puerto serial
    	Serial.println("cm");              // le coloca a la distancia los centimetros "cm"
      	//tone(Buzzer,fr*(x+1));    // inicia el zumbido
      if(x==0){
          tone(Buzzer1,2093);//1047);  //DO 5ta 8va
        }
      else if(x==1){
          tone(Buzzer2,2349);//1175);  //RE 5ta 8va
        }
      else if(x==2){
          tone(Buzzer3,2637);//1319);  //MI 5ta 8va
        }
      else if(x==3){
          tone(Buzzer4,2794);//1397);  //FA 5ta 8va
        }
      else if(x==4){
          tone(Buzzer5,3136);//1568);  //SOL 5ta 8va
      } 
      else if(x==5){
          tone(Buzzer6,3520);//1760);  //LA 5ta 8va
        }
      else if(x==6){
          tone(Buzzer7,3951);//1976);  //SI 5ta 8va
        }
      else if(x==7){
          tone(Buzzer8,2093);//2093);  //DO 6ta 8va
        }  
      	delay(700);                    
    	noTone(Buzzer1);               // lo detiene a los dos segundos
      noTone(Buzzer2);
      noTone(Buzzer3);
      noTone(Buzzer4);
      noTone(Buzzer5);
      noTone(Buzzer6);
      noTone(Buzzer7);
      noTone(Buzzer8);
    } 
    delay(1);
    x+=1;
  }while (x<Ns);
  x=0;
}

double MedirDist(int sensorTrig, int sensorEcho)
{
  digitalWrite(sensorTrig, LOW);
  delayMicroseconds(2);
  digitalWrite(sensorTrig, HIGH);   // genera el pulso de triger por 10ms
  delayMicroseconds(5);
  digitalWrite(sensorTrig, LOW);
  
  duracion = pulseIn(sensorEcho, HIGH);
  distancia = (duracion/2) / 29;   
  return distancia;
}
