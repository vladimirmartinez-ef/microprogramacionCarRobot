#include <Servo.h>          //Servo motor library. This is standard library
#include <NewPing.h>        //Ultrasonic sensor function library. You must install this library
#include <ArduinoCarro.h>  //locura.com

// //our L298N control pins
// const int LeftMotorForward = 5;
// const int LeftMotorBackward = 4;
// const int RightMotorForward = 3;
// const int RightMotorBackward = 2;
Carro micro;
int giro = 90;
int tiempo = 410;
//sensor pins
#define trig_pin A1 //analog input 1
#define echo_pin A2 //analog input 2

#define maximum_distance 200
boolean goesForward = false;
int distance = 100;

NewPing sonar(trig_pin, echo_pin, maximum_distance); //sensor function
Servo servo_motor; //our servo name


void setup(){

//   pinMode(RightMotorForward, OUTPUT);
//   pinMode(LeftMotorForward, OUTPUT);
//   pinMode(LeftMotorBackward, OUTPUT);
//   pinMode(RightMotorBackward, OUTPUT);
  
  servo_motor.attach(11); //our servo pin

  servo_motor.write(90);
  delay(2000);
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);
}

void loop(){

  int distanceRight = 0;
  int distanceLeft = 0;
  delay(50);

  if (distance <= 20){
    moveStop();
    delay(300);
    moveBackward();
    delay(400);
    moveStop();
    delay(300);
    distanceRight = lookRight();
    delay(300);
    distanceLeft = lookLeft();
    delay(300);

    if (distance >= distanceLeft){
      turnRight();
      moveStop();
    }
    else{
      turnLeft();
      moveStop();
    }
  }
  else{
    moveForward(); 
  }
    distance = readPing();
}

int lookRight(){  
  servo_motor.write(10);
  delay(500);
  int distance = readPing();
  delay(100);
  servo_motor.write(90);
  return distance;
}

int lookLeft(){
  servo_motor.write(170);
  delay(500);
  int distance = readPing();
  delay(100);
  servo_motor.write(90);
  return distance;
  delay(100);
}

int readPing(){
  delay(70);
  int cm = sonar.ping_cm();
  if (cm==0){
    cm=250;
  }
  return cm;
}

void moveStop(){
    micro.mover(0,0);
}

void moveForward(){

  if(!goesForward){
    goesForward=true;
    micro.mover(10,10);
  }
}

void moveBackward(){
  goesForward=false;
    micro.mover(-10,-10);
}

void turnRight(){
    micro.girar(giro,tiempo);  
}

void turnLeft(){
    micro.girar(giro * -1, tiempo);
}
