#include <AX12A.h>
#include <String.h>

#define DirectionPin  (42u)
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

double hasil_kananb[3];
double hasil_kanand[3];
double hasil_kirib[3];
double hasil_kirid[3];

const double l1 = 35.0;
const double l2 = 70.0;
const double l3 = 130.0;

const double initial_angle1 = 105.0;
const double initial_angle2 = 150.0;
const double initial_angle3 = 60.0;

const double z_rest = -130.0;
const double y_rest = 105.0;

int IDservo1;
int IDservo2;
int IDservo3;

void transformasi(double x, double y, double z, String kaki, double hasil[3] ) {
//  if(kaki == "kananbelakang"){
//    IDservo1 = Belakangkanan1;
//    IDservo2 = Belakangkanan2;
//    IDservo3 = Belakangkanan3;
//  }
//  else if(kaki == "kiribelakang"){
//    IDservo1 = Belakangkiri1;
//    IDservo2 = Belakangkiri2;
//    IDservo3 = Belakangkiri3;
//  }
//  else if(kaki == "kiridepan"){
//    IDservo1 = Depankiri1;
//    IDservo2 = Depankiri2;
//    IDservo3 = Depankiri3;
//  }
//  else if(kaki == "kanandepan"){
//    IDservo1 = Depankanan1;
//    IDservo2 = Depankanan2;
//    IDservo3 = Depankanan3;
//  }
  
  y += y_rest;
  z += z_rest;

  double b = atan(x / y) * (180 / PI); // base angle

  double l = sqrt(x * x + y * y); // x and y extension

  l = l - l1;

  double c = sqrt (l * l + z * z);

  double a2 = acos((l2 * l2 + l3 * l3 - c * c) / (2 * l2 * l3)) * (180 / PI);

  double a1 = asin(l3 * sin(a2 / (180 / PI)) / c) * (180 / PI) + atan(z / l) * (180 / PI); //( atan(z/l) - acos(l2*l2 - l3*l3 + c*c)/2*l2*c ) * (180 / 3.1415);

//  delay(5000);

//  Serial.println(kaki);
//  Serial.println(kaki);
//  Serial.println(kaki);
//
//  Serial.println(b);
//  Serial.println(a1);
//  Serial.println(a2);
//  Serial.println(IDservo1);
//  Serial.println(IDservo2);
//  Serial.println(IDservo3);

hasil[0] = b;
hasil[1] = a1;
hasil[2] = a2;  

//  Serial.println(Belakangkanan1);
//  Serial.println(Belakangkanan2);
//  Serial.println(Belakangkanan3);
  
//  gerakservo1(b, IDservo1);
//  gerakservo2(a1, IDservo2);
//  gerakservo3(a2, IDservo3);

}

void gerakmaju1(int belakangka1, int belakangka2, int belakangka3, int belakangki1, int belakangki2, int belakangki3, int depanki1, int depanki2, int depanki3, int depanka1, int depanka2, int depanka3, double hasilkab[3], double hasilkib[3], double hasilkid[3], double hasilkad[3]){
  hasilkib[0] = hasilkib[0] * (-1);
  hasilkid[0] = hasilkid[0] * (-1);

  hasilkab[0] = hasilkab[0] + 150.0;
  hasilkib[0] = hasilkib[0] + 150.0;
  hasilkid[0] = hasilkid[0] + 150.0;
  hasilkad[0] = hasilkad[0] + 150.0;

  hasilkab[1] = hasilkab[1] + initial_angle2;
  hasilkib[1] = hasilkib[1] + initial_angle2;
  hasilkid[1] = hasilkid[1] + initial_angle2;
  hasilkad[1] = hasilkad[1] + initial_angle2;

  hasilkab[2] = hasilkab[2] + initial_angle3;
  hasilkib[2] = hasilkib[2] + initial_angle3;
  hasilkid[2] = hasilkid[2] + initial_angle3;
  hasilkad[2] = hasilkad[2] + initial_angle3;

  // Konversi 1 dimulai dari kanan belakang servo1 dan diakhiri dengan kanan depan servo3
  double konversi1 = map(hasilkab[0], 0, 300, 0, 1024);
  double konversi2 = map(hasilkab[1], 0, 300, 0, 1024);
  double konversi3 = map(hasilkab[2], 300, 0, 0, 1024);

  double konversi4 = map(hasilkib[0], 0, 300, 0, 1024);
  double konversi5 = map(hasilkib[1], 0, 300, 0, 1024);
  double konversi6 = map(hasilkib[2], 300, 0, 0, 1024);

  double konversi7 = map(hasilkid[0], 0, 300, 0, 1024);
  double konversi8 = map(hasilkid[1], 0, 300, 0, 1024);
  double konversi9 = map(hasilkid[2], 300, 0, 0, 1024);

  double konversi10 = map(hasilkad[0], 0, 300, 0, 1024);
  double konversi11 = map(hasilkad[1], 0, 300, 0, 1024);
  double konversi12 = map(hasilkad[2], 300, 0, 0, 1024);

  ax12a.moveSpeed(belakangka1, konversi1 , 200);
  ax12a.moveSpeed(belakangka2, konversi2 , 200);
  ax12a.moveSpeed(belakangka3, konversi3 , 200);
  ax12a.moveSpeed(belakangki1, konversi4 , 200);
  ax12a.moveSpeed(belakangki2, konversi5 , 200);
  ax12a.moveSpeed(belakangki3, konversi6 , 200);
  ax12a.moveSpeed(depanki1, konversi7 , 200);
  ax12a.moveSpeed(depanki2, konversi8 , 200);
  ax12a.moveSpeed(depanki3, konversi9 , 200);
  ax12a.moveSpeed(depanka1, konversi10 , 200);
  ax12a.moveSpeed(depanka2, konversi11 , 200);
  ax12a.moveSpeed(depanka3, konversi12 , 200);
}

void setup(){
  Serial.begin(10000000);
  ax12a.begin(BaudRate, DirectionPin, &Serial);
  ax12a.setEndless(IDservo2, OFF);
}

void loop(){
//  delay(2000);
//  gerak(0,0,0,"kiridepan");
//  gerak(0,0,0,"kiribelakang");
//  gerak (0,0,0,"kananbelakang");
//  gerak (0,0,0,"kanandepan");
//  delay(2000);
//  gerak(70,20,40,"kananbelakang");
//  delay(1000);
//  gerak (70,20,7.32,"kananbelakang");
//  delay(2000);  
//  gerak(70,20,40,"kanandepan");
//  delay(1000);
//  gerak (70,20,7.32,"kanandepan");
//  delay(2000);
//  gerak(-70,0,0,"kiridepan");
//  gerak(-70,0,0,"kiribelakang");
//  gerak (0,0,0,"kananbelakang");
//  gerak (0,0,0,"kanandepan");
//
//  delay(2000);
//  gerak(0,0,0,"kiridepan");
//  gerak(0,0,0,"kiribelakang");
//  gerak (0,0,0,"kananbelakang");
//  gerak (0,0,0,"kanandepan");
//  delay(2000);
//  gerak(70,20,40,"kiribelakang");
//  delay(1000);
//  gerak (70,20,7.32,"kiribelakang");
//  delay(2000);  
//  gerak(70,20,40,"kiridepan");
//  delay(1000);
//  gerak (70,20,7.32,"kiridepan");
//  delay(2000);
//  gerak(-70,0,0,"kanandepan");
//  gerak(-70,0,0,"kananbelakang");
//  gerak (0,0,0,"kiribelakang");
//  gerak (0,0,0,"kiridepan");
//
//  delay(2000);

//  delay(2000);
//  gerak(0,0,0,"kiridepan");
//  gerak(0,0,0,"kiribelakang");
//  gerak (0,0,0,"kananbelakang");
//  gerak (0,0,0,"kanandepan");
//  delay(2000);
//  gerak(70,20,40,"kananbelakang");
//  delay(1000);
//  gerak (70,20,7.32,"kananbelakang");
//  delay(2000);  
//  gerak(70,20,40,"kanandepan");
//  delay(1000);
//  gerak (70,20,7.32,"kanandepan");
//  delay(2000);
//  gerak(70,20,40,"kiribelakang");
//  delay(1000);
//  gerak (70,20,7.32,"kiribelakang");
//  delay(2000);  
//  gerak(70,20,40,"kiridepan");
//  delay(1000);
//  gerak (70,20,7.32,"kiridepan");
//  delay(2000);

  delay(2000);
  transformasi(0,0,0,"kananbelakang", hasil_kananb);
  transformasi(0,0,0,"kiribelakang", hasil_kirib);
  transformasi(0,0,0,"kiridepan", hasil_kirid);
  transformasi(0,0,0,"kanandepan", hasil_kanand);
  delay(4000);
  gerakmaju1(Belakangkanan1, Belakangkanan2, Belakangkanan3, Belakangkiri1, Belakangkiri2, Belakangkiri3, Depankiri1, Depankiri2, Depankiri3, Depankanan1, Depankanan2, Depankanan3, hasil_kananb, hasil_kirib, hasil_kirid, hasil_kanand);
  transformasi(70,20,40,"kananbelakang", hasil_kananb);
  delay(2000);
  gerakmaju1(Belakangkanan1, Belakangkanan2, Belakangkanan3, Belakangkiri1, Belakangkiri2, Belakangkiri3, Depankiri1, Depankiri2, Depankiri3, Depankanan1, Depankanan2, Depankanan3, hasil_kananb, hasil_kirib, hasil_kirid, hasil_kanand);
//  Serial.println(hasil_kananb[
//  Serial.println(hasil_kananb[1]);
//  Serial.println(hasil_kananb[2]);
//  gerakmaju1(Belakangkanan1, Belakangkanan2, Belakangkanan3, Belakangkiri1, Belakangkiri2, Belakangkiri3, Depankiri1, Depankiri2, Depankiri3, Depankiri1, Depankiri2, Depankiri3, hasil_kananb, hasil_kirib, hasil_kirid, hasil_kanand);  
//  transformasi(70,20,7,"kananbelakang", hasil_kananb);
  delay(500);
//  gerakmaju1(Belakangkanan1, Belakangkanan2, Belakangkanan3, Belakangkiri1, Belakangkiri2, Belakangkiri3, Depankiri1, Depankiri2, Depankiri3, Depankiri1, Depankiri2, Depankiri3, hasil_kananb, hasil_kirib, hasil_kirid, hasil_kanand);  
//  transformasi(70,20,40,"kanandepan", hasil_kanand);
//  delay(500);
//  gerakmaju1(Belakangkanan1, Belakangkanan2, Belakangkanan3, Belakangkiri1, Belakangkiri2, Belakangkiri3, Depankiri1, Depankiri2, Depankiri3, Depankiri1, Depankiri2, Depankiri3, hasil_kananb, hasil_kirib, hasil_kirid, hasil_kanand);  
//  transformasi(70,20,7,"kanandepan", hasil_kanand);
//  delay(500);
//  transformasi(0,0,0,"kananbelakang", hasil_kananb);
//  transformasi(-70,0,0,"kiribelakang", hasil_kirib);
//  transformasi(-70,0,0,"kiridepan", hasil_kirid);
//  transformasi(0,0,0,"kanandepan", hasil_kanand);
//  //////
//  delay(1000);
//  gerakmaju1(Belakangkanan1, Belakangkanan2, Belakangkanan3, Belakangkiri1, Belakangkiri2, Belakangkiri3, Depankiri1, Depankiri2, Depankiri3, Depankiri1, Depankiri2, Depankiri3, hasil_kananb, hasil_kirib, hasil_kirid, hasil_kanand);
//  transformasi(70,20,40,"kiribelakang", hasil_kirib);
//  delay(500);
//  gerakmaju1(Belakangkanan1, Belakangkanan2, Belakangkanan3, Belakangkiri1, Belakangkiri2, Belakangkiri3, Depankiri1, Depankiri2, Depankiri3, Depankiri1, Depankiri2, Depankiri3, hasil_kananb, hasil_kirib, hasil_kirid, hasil_kanand);  
//  transformasi(70,20,7,"kiribelakang", hasil_kirib);
//  delay(500);
//  gerakmaju1(Belakangkanan1, Belakangkanan2, Belakangkanan3, Belakangkiri1, Belakangkiri2, Belakangkiri3, Depankiri1, Depankiri2, Depankiri3, Depankiri1, Depankiri2, Depankiri3, hasil_kananb, hasil_kirib, hasil_kirid, hasil_kanand);  
//  transformasi(70,20,40,"kiridepan", hasil_kirid);
//  delay(500);
//  gerakmaju1(Belakangkanan1, Belakangkanan2, Belakangkanan3, Belakangkiri1, Belakangkiri2, Belakangkiri3, Depankiri1, Depankiri2, Depankiri3, Depankiri1, Depankiri2, Depankiri3, hasil_kananb, hasil_kirib, hasil_kirid, hasil_kanand);  
//  transformasi(70,20,7,"kiridepan", hasil_kirid);
//  delay(500);
//  transformasi(-70,0,0,"kananbelakang", hasil_kananb);
//  transformasi(0,0,0,"kiribelakang", hasil_kirib);
//  transformasi(0,0,0,"kiridepan", hasil_kirid);
//  transformasi(-70,0,0,"kanandepan", hasil_kanand);
//  delay(1500);
  
}



void gerakservo1(double sudut1, int ID1) {
  double sudut;

  if(ID1 == 3 || ID1 == 5){
    sudut1 = sudut1 * (-1); 
  }
  sudut = sudut1 + 150.0;

  double konversi = map(sudut, 0, 300, 0, 1024);

  ax12a.ledStatus(ID1, ON);
  ax12a.moveSpeed(ID1, konversi , 200);
}

void gerakservo2(double sudut2, int ID2) {
  double sudut = sudut2 + initial_angle2;

  double konversi = map(sudut, 0, 300, 0, 1024); 

  ax12a.ledStatus(ID2, ON);
  ax12a.moveSpeed(ID2, konversi , 200);
}

void gerakservo3(double sudut3, int ID3) {
  double sudut = sudut3 + initial_angle3;

  double konversi = map(sudut, 300, 0, 0, 1024);

  ax12a.ledStatus(ID3, ON);
  ax12a.moveSpeed(ID3, konversi , 200);
}
