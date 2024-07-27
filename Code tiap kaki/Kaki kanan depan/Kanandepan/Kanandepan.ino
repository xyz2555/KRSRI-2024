#include <AX12A.h>

#define DirectionPin  (42u)
#define BaudRate    (1000000ul)
#define IDservo1    (8u)
#define IDservo2    (14u)
#define IDservo3    (20u)

const double l1 = 35.0;
const double l2 = 40.0;
const double l3 = 130.0;

const double initial_angle1 = 105.0;
const double initial_angle2 = 150.0;
const double initial_angle3 = 60.0;

const double z_rest = -130.0;
const double y_rest = 75.0;


void setup(){
  Serial.begin(10000000);
  ax12a.begin(BaudRate, DirectionPin, &Serial);
  ax12a.setEndless(IDservo2, OFF);
}

void loop(){
  gerak(20, 20, 20);
  delay(5000);
  gerak(0, 0, 0);
}

double Konversi(double sudut) {
  double konversi = map(sudut, 0, 300, 0, 1024);

  return konversi;
}

void gerak(double x, double y, double z) {
  y += y_rest;
  z += z_rest;

  double b = atan(x / y) * (180 / PI); // base angle

  double l = sqrt(x * x + y * y); // x and y extension

  l = l - l1;

  double c = sqrt (l * l + z * z);

  double a2 = acos((l2 * l2 + l3 * l3 - c * c) / (2 * l2 * l3)) * (180 / PI);

  double a1 = asin(l3 * sin(a2 / (180 / PI)) / c) * (180 / PI) + atan(z / l) * (180 / PI); //( atan(z/l) - acos(l2*l2 - l3*l3 + c*c)/2*l2*c ) * (180 / 3.1415);

  delay(5000);
  Serial.println(b);
  Serial.println(a1);
  Serial.println(a2);

  gerakservo1(b);
  gerakservo2(a1);
  gerakservo3(a2);

}

void gerakservo1(double sudut1) {
  double sudut = sudut1 + 150.0;

  double konversi = map(sudut, 0, 300, 0, 1024);

  ax12a.ledStatus(IDservo1, ON);
  ax12a.moveSpeed(IDservo1, konversi , 200);
}

void gerakservo2(double sudut2) {
  double sudut = sudut2 + initial_angle2;

  double konversi = map(sudut, 0, 300, 0, 1024);

  ax12a.ledStatus(IDservo2, ON);
  ax12a.moveSpeed(IDservo2, konversi , 200);
}

void gerakservo3(double sudut3) {
  double sudut = sudut3 + initial_angle3;

  double konversi = map(sudut, 300, 0, 0, 1024);

  ax12a.ledStatus(IDservo3, ON);
  ax12a.moveSpeed(IDservo3, konversi , 200);
}
