#include <Servo.h>
// definição dos pinos usados na c.p.u.

#define ESC_A 9 // ESC

/*canais do RC*/
const int chA = 7;
const int chB = 6;
const int chC = 5;
const int chD = 4;
/**/

//variaveis de alocação para canais do RC
float ch1;
float ch2;
float ch3;
float ch4;

//***configuracao ESC
#define ESC_ARM_DELAY 5000
// valores maximos e minimos da ESC
#define ESC_MAX_SIGNAL 2000
#define ESC_MIN_SIGNAL 700

// valores maximos e minimos do RC
/*Canais right stick*/
#define RC_HIGH_CH1 1948 //Left/Right 
#define RC_LOW_CH1 981
#define RC_HIGH_CH2 1965 //Up/Down
#define RC_LOW_CH2 985
/**/
/*Canais left stick*/
#define RC_HIGH_CH3 1968 //Up/Down
#define RC_LOW_CH3 985
#define RC_HIGH_CH4 1961 //Left/Right
#define RC_LOW_CH4 991

int va;
// "Objeto" ESC...
Servo a;

void setup()
{
  Serial.begin(9600);
  pinMode(chA, INPUT);
    pinMode(chB, INPUT);
      pinMode(chC, INPUT);
        pinMode(chD, INPUT);
     
  a.attach(ESC_A); 
  delay(100);   
  Arm();
}

void loop()
{
  ch3 =  pulseIn(chC, HIGH);
  va = ch3;
//  delay(1000);
  updateMotors();
}

void updateMotors(){
  a.write(va);
}

void Arm()
{
  a.write(ESC_MIN_SIGNAL);
  
  delay(ESC_ARM_DELAY);
}
