#include <AX12A.h>

#define DirectionPin  (10u)
#define BaudRate    (1000000ul)

#define Belakangkanan1  (1u)
#define Belakangkanan2  (7u)
#define Belakangkanan3  (13u)

#define Belakangkiri1 (3u)
#define Belakangkiri2 (9u)
#define Belakangkiri3 (15u)

#define Depankiri1  (5u)
#define Depankiri2  (11u)
#define Depankiri3  (17u)

#define Depankanan1 (8u)
#define Depankanan2 (14u)
#define Depankanan3 (20u)

const double l1 = 35.0;
const double l2 = 70.0;
const double l3 = 130.0;

const double initial_angle1 = 105.0;
const double initial_angle2 = 150.0;
const double initial_angle3 = 60.0;

const double z_rest = -130.0;
const double y_rest = 105.0;

int i;

void setup(){
  Serial.begin(10000000);
  ax12a.begin(BaudRate, DirectionPin, &Serial);
  
//  ax12a.setID(3, 25);
//  ax12a.setEndless(IDservo2, OFF);
}

void loop(){
//  for(int i = 0; i <= 7 ; i++){
//    ax12a.ledStatus(i, ON);
//    ax12a.moveSpeed(i, 600, 200);
//    ax12a.setEndless(16, OFF);
//  }
//  delay(500);
//  for(int i= 0; i <= 7 ; i++){
//    ax12a.moveSpeed(i, 512, 200);
//    ax12a.ledStatus(i, OFF);
//  }
//  delay(500);
//
ax12a.ledStatus(25, ON);
ax12a.moveSpeed(25, 512, 200);
delay(500);
ax12a.moveSpeed(25, 600, 200);
ax12a.ledStatus(25,OFF);
delay(1000);
}
