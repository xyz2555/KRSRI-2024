#include <AX12A.h>
#include <String.h>

#define DirectionPin  (21u)
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

double pos[15];


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

  y += y_rest;
  z += z_rest;

  double b = atan(x / y) * (180 / PI); // base angle

  double l = sqrt(x * x + y * y); // x and y extension

  l = l - l1;

  double c = sqrt (l * l + z * z);

  double a2 = acos((l2 * l2 + l3 * l3 - c * c) / (2 * l2 * l3)) * (180 / PI);

  double a1 = asin(l3 * sin(a2 / (180 / PI)) / c) * (180 / PI) + atan(z / l) * (180 / PI); //( atan(z/l) - acos(l2*l2 - l3*l3 + c*c)/2*l2*c ) * (180 / 3.1415);


//  Serial.println(b);
//  Serial.println(a1);
//  Serial.println(a2);


hasil[0] = b;
hasil[1] = a1;
hasil[2] = a2;  



}

void gerakmaju1(int belakangka1, int belakangka2, int belakangka3, int belakangki1, int belakangki2, int belakangki3, int depanki1, int depanki2, int depanki3, int depanka1, int depanka2, int depanka3, double hasilkab[3], double hasilkib[3], double hasilkid[3], double hasilkad[3], double posi[]){
  hasilkib[0] = hasilkib[0] * (-1);
  hasilkid[0] = hasilkid[0] * (-1);

  hasilkab[0] = hasilkab[0] + 195.0;
  hasilkib[0] = hasilkib[0] + 105.0;
  hasilkid[0] = hasilkid[0] + 195.0;
  hasilkad[0] = hasilkad[0] + 105.0;

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


  double nilaiTertinggi;
  int posisiskrg[15]; 
  double selisih[15]; 
  double selisih1[15];

  posisiskrg[1]=posi[1];
  posisiskrg[2]=posi[2];
  posisiskrg[3]=posi[3];
  posisiskrg[4]=posi[4];
  posisiskrg[5]=posi[5];
  posisiskrg[6]=posi[6];
  posisiskrg[7]=posi[7];
  posisiskrg[8]=posi[8];
  posisiskrg[9]=posi[9];
  posisiskrg[10]=posi[10];
  posisiskrg[11]=posi[11];
  posisiskrg[12]=posi[12];

  selisih1[1]=posisiskrg[1]-konversi1;
  selisih1[2]=posisiskrg[2]-konversi2;
  selisih1[3]=posisiskrg[3]-konversi3;
  selisih1[4]=posisiskrg[4]-konversi4;
  selisih1[5]=posisiskrg[5]-konversi5;
  selisih1[6]=posisiskrg[6]-konversi6;
  selisih1[7]=posisiskrg[7]-konversi7;
  selisih1[8]=posisiskrg[8]-konversi8;
  selisih1[9]=posisiskrg[9]-konversi9;
  selisih1[10]=posisiskrg[10]-konversi10;
  selisih1[11]=posisiskrg[11]-konversi11;
  selisih1[12]=posisiskrg[12]-konversi12;

  selisih[1]=abs(posisiskrg[1]-konversi1);
  selisih[2]=abs(posisiskrg[2]-konversi2);
  selisih[3]=abs(posisiskrg[3]-konversi3);
  selisih[4]=abs(posisiskrg[4]-konversi4);
  selisih[5]=abs(posisiskrg[5]-konversi5);
  selisih[6]=abs(posisiskrg[6]-konversi6);
  selisih[7]=abs(posisiskrg[7]-konversi7);
  selisih[8]=abs(posisiskrg[8]-konversi8);
  selisih[9]=abs(posisiskrg[9]-konversi9);
  selisih[10]=abs(posisiskrg[10]-konversi10);
  selisih[11]=abs(posisiskrg[11]-konversi11);
  selisih[12]=abs(posisiskrg[12]-konversi12);

  // Bandingkan dengan nilai lainnya
  // Mulai dengan nilai pertama
  nilaiTertinggi = selisih[1];
  
  nilaiTertinggi = max(nilaiTertinggi, selisih[2]);
  nilaiTertinggi = max(nilaiTertinggi, selisih[3]);
  nilaiTertinggi = max(nilaiTertinggi, selisih[4]);
  nilaiTertinggi = max(nilaiTertinggi, selisih[5]);
  nilaiTertinggi = max(nilaiTertinggi, selisih[6]);
  nilaiTertinggi = max(nilaiTertinggi, selisih[7]);
  nilaiTertinggi = max(nilaiTertinggi, selisih[8]);
  nilaiTertinggi = max(nilaiTertinggi, selisih[9]);
  nilaiTertinggi = max(nilaiTertinggi, selisih[10]);
  nilaiTertinggi = max(nilaiTertinggi, selisih[11]);
  nilaiTertinggi = max(nilaiTertinggi, selisih[12]);
  
for(int i=0; i <= nilaiTertinggi/4; i++){

  Serial.println(posisiskrg[1] + (selisih1[1]/nilaiTertinggi)*i);
  Serial.println(posisiskrg[2] + (selisih1[2]/nilaiTertinggi)*i);
  
  
  ax12a.moveSpeed(belakangka1, posisiskrg[1] - (selisih1[1]/nilaiTertinggi)*i*4 , 200);
  ax12a.moveSpeed(belakangka2, posisiskrg[2] - (selisih1[2]/nilaiTertinggi)*i*4, 200);
  ax12a.moveSpeed(belakangka3, posisiskrg[3] - (selisih1[3]/nilaiTertinggi)*i*4 , 200);
  ax12a.moveSpeed(belakangki1, posisiskrg[4] - (selisih1[4]/nilaiTertinggi)*i*4, 200);
  ax12a.moveSpeed(belakangki2, posisiskrg[5] - (selisih1[5]/nilaiTertinggi)*i*4 , 200);
  ax12a.moveSpeed(belakangki3, posisiskrg[6] - (selisih1[6]/nilaiTertinggi)*i*4 , 200);
  ax12a.moveSpeed(depanki1, posisiskrg[7] - (selisih1[7]/nilaiTertinggi)*i*4, 200);
  ax12a.moveSpeed(depanki2, posisiskrg[8] - (selisih1[8]/nilaiTertinggi)*i*4 , 200);
  ax12a.moveSpeed(depanki3, posisiskrg[9] - (selisih1[9]/nilaiTertinggi)*i*4 , 200);
  ax12a.moveSpeed(depanka1, posisiskrg[10] - (selisih1[10]/nilaiTertinggi)*i*4 , 200);
  ax12a.moveSpeed(depanka2, posisiskrg[11] - (selisih1[11]/nilaiTertinggi)*i*4 , 200);
  ax12a.moveSpeed(depanka3, posisiskrg[12] - (selisih1[12]/nilaiTertinggi)*i*4 , 200);
  delay(1);
  }
  
 posi[1]=konversi1;
 posi[2]=konversi2;
 posi[3]=konversi3;
 posi[4]=konversi4;
 posi[5]=konversi5;
 posi[6]=konversi6;
 posi[7]=konversi7;
 posi[8]=konversi8;
 posi[9]=konversi9;
 posi[10]=konversi10;
 posi[11]=konversi11;
 posi[12]=konversi12;
}

void setup(){
  Serial.begin(10000000);
  ax12a.begin(BaudRate, DirectionPin, &Serial);
  ax12a.setEndless(IDservo2, OFF);

  for(int i = 0; i<=15; i++){
    pos[i]=512;
  }

  ax12a.moveSpeed(Belakangkanan1, pos[1] , 200);
  ax12a.moveSpeed(Belakangkanan2, pos[2], 200);
  ax12a.moveSpeed(Belakangkanan3, pos[3] , 200);
  ax12a.moveSpeed(Belakangkiri1, pos[4] , 200);
  ax12a.moveSpeed(Belakangkiri2, pos[5] , 200);
  ax12a.moveSpeed(Belakangkiri3, pos[6] , 200);
  ax12a.moveSpeed(Depankiri1, pos[7], 200);
  ax12a.moveSpeed(Depankiri2, pos[8] , 200);
  ax12a.moveSpeed(Depankiri3, pos[9] , 200);
  ax12a.moveSpeed(Depankanan1, pos[10] , 200);
  ax12a.moveSpeed(Depankanan2, pos[11] , 200);
  ax12a.moveSpeed(Depankanan3, pos[12] , 200);
  delay(1500);
  transformasi(-50,-30,40,"kananbelakang", hasil_kananb);
  transformasi(-50,-30,40,"kiribelakang", hasil_kirib);
  transformasi(50,-30,40,"kiridepan", hasil_kirid);
  transformasi(50,-30,40,"kanandepan", hasil_kanand);
  gerakmaju1(Belakangkanan1, Belakangkanan2, Belakangkanan3, Belakangkiri1, Belakangkiri2, Belakangkiri3, Depankiri1, Depankiri2, Depankiri3, Depankanan1, Depankanan2, Depankanan3, hasil_kananb, hasil_kirib, hasil_kirid, hasil_kanand, pos);

  transformasi(-110,0,0,"kananbelakang", hasil_kananb);
  transformasi(-55,0,0,"kiribelakang", hasil_kirib);
  transformasi(55,0,0,"kiridepan", hasil_kirid);
  transformasi(0,0,0,"kanandepan", hasil_kanand);
  gerakmaju1(Belakangkanan1, Belakangkanan2, Belakangkanan3, Belakangkiri1, Belakangkiri2, Belakangkiri3, Depankiri1, Depankiri2, Depankiri3, Depankanan1, Depankanan2, Depankanan3, hasil_kananb, hasil_kirib, hasil_kirid, hasil_kanand, pos);


delay(2000);
}

void loop(){
//  majuSemua();
  cobass;
//mencoba();
}
void maju(){
  //step pertama
  transformasi(0,0,40,"kananbelakang", hasil_kananb);
  transformasi(-55,0,0,"kiribelakang", hasil_kirib);
  transformasi(55,0,0,"kiridepan", hasil_kirid);
  transformasi(0,0,0,"kanandepan", hasil_kanand);
  gerakmaju1(Belakangkanan1, Belakangkanan2, Belakangkanan3, Belakangkiri1, Belakangkiri2, Belakangkiri3, Depankiri1, Depankiri2, Depankiri3, Depankanan1, Depankanan2, Depankanan3, hasil_kananb, hasil_kirib, hasil_kirid, hasil_kanand, pos);

  transformasi(0,0,0,"kananbelakang", hasil_kananb);
  transformasi(-55,0,0,"kiribelakang", hasil_kirib);
  transformasi(55,0,0,"kiridepan", hasil_kirid);
  transformasi(0,0,0,"kanandepan", hasil_kanand);
  gerakmaju1(Belakangkanan1, Belakangkanan2, Belakangkanan3, Belakangkiri1, Belakangkiri2, Belakangkiri3, Depankiri1, Depankiri2, Depankiri3, Depankanan1, Depankanan2, Depankanan3, hasil_kananb, hasil_kirib, hasil_kirid, hasil_kanand, pos);

  transformasi(0,0,0,"kananbelakang", hasil_kananb);
  transformasi(-55,0,0,"kiribelakang", hasil_kirib);
  transformasi(55,0,0,"kiridepan", hasil_kirid);
  transformasi(110,0,40,"kanandepan", hasil_kanand);
  gerakmaju1(Belakangkanan1, Belakangkanan2, Belakangkanan3, Belakangkiri1, Belakangkiri2, Belakangkiri3, Depankiri1, Depankiri2, Depankiri3, Depankanan1, Depankanan2, Depankanan3, hasil_kananb, hasil_kirib, hasil_kirid, hasil_kanand, pos);

  transformasi(0,0,0,"kananbelakang", hasil_kananb);
  transformasi(-55,0,0,"kiribelakang", hasil_kirib);
  transformasi(55,0,0,"kiridepan", hasil_kirid);
  transformasi(110,0,0,"kanandepan", hasil_kanand);
  gerakmaju1(Belakangkanan1, Belakangkanan2, Belakangkanan3, Belakangkiri1, Belakangkiri2, Belakangkiri3, Depankiri1, Depankiri2, Depankiri3, Depankanan1, Depankanan2, Depankanan3, hasil_kananb, hasil_kirib, hasil_kirid, hasil_kanand, pos);
  
//  transformasi(-55,0,0,"kananbelakang", hasil_kananb);
//  transformasi(-110,0,0,"kiribelakang", hasil_kirib);
//  transformasi(0,0,0,"kiridepan", hasil_kirid);
//  transformasi(55,0,0,"kanandepan", hasil_kanand);
//  gerakmaju1(Belakangkanan1, Belakangkanan2, Belakangkanan3, Belakangkiri1, Belakangkiri2, Belakangkiri3, Depankiri1, Depankiri2, Depankiri3, Depankanan1, Depankanan2, Depankanan3, hasil_kananb, hasil_kirib, hasil_kirid, hasil_kanand, pos);
}

void maju2(){
  transformasi(-55,0,0,"kananbelakang", hasil_kananb);
  transformasi(-110,0,0,"kiribelakang", hasil_kirib);
  transformasi(0,0,0,"kiridepan", hasil_kirid);
  transformasi(55,0,0,"kanandepan", hasil_kanand);
  gerakmaju1(Belakangkanan1, Belakangkanan2, Belakangkanan3, Belakangkiri1, Belakangkiri2, Belakangkiri3, Depankiri1, Depankiri2, Depankiri3, Depankanan1, Depankanan2, Depankanan3, hasil_kananb, hasil_kirib, hasil_kirid, hasil_kanand, pos);

  transformasi(-55,0,0,"kananbelakang", hasil_kananb);
  transformasi(0,0,40,"kiribelakang", hasil_kirib);
  transformasi(0,0,0,"kiridepan", hasil_kirid);
  transformasi(55,0,0,"kanandepan", hasil_kanand);
  gerakmaju1(Belakangkanan1, Belakangkanan2, Belakangkanan3, Belakangkiri1, Belakangkiri2, Belakangkiri3, Depankiri1, Depankiri2, Depankiri3, Depankanan1, Depankanan2, Depankanan3, hasil_kananb, hasil_kirib, hasil_kirid, hasil_kanand, pos);

  transformasi(-55,0,0,"kananbelakang", hasil_kananb);
  transformasi(0,0,0,"kiribelakang", hasil_kirib);
  transformasi(0,0,0,"kiridepan", hasil_kirid);
  transformasi(55,0,0,"kanandepan", hasil_kanand);
  gerakmaju1(Belakangkanan1, Belakangkanan2, Belakangkanan3, Belakangkiri1, Belakangkiri2, Belakangkiri3, Depankiri1, Depankiri2, Depankiri3, Depankanan1, Depankanan2, Depankanan3, hasil_kananb, hasil_kirib, hasil_kirid, hasil_kanand, pos);

  transformasi(-55,0,0,"kananbelakang", hasil_kananb);
  transformasi(0,0,0,"kiribelakang", hasil_kirib);
  transformasi(110,0,40,"kiridepan", hasil_kirid);
  transformasi(55,0,0,"kanandepan", hasil_kanand);
  gerakmaju1(Belakangkanan1, Belakangkanan2, Belakangkanan3, Belakangkiri1, Belakangkiri2, Belakangkiri3, Depankiri1, Depankiri2, Depankiri3, Depankanan1, Depankanan2, Depankanan3, hasil_kananb, hasil_kirib, hasil_kirid, hasil_kanand, pos);

}

void maju3(){
  transformasi(-55,0,0,"kananbelakang", hasil_kananb);
  transformasi(0,0,0,"kiribelakang", hasil_kirib);
  transformasi(110,0,0,"kiridepan", hasil_kirid);
  transformasi(55,0,0,"kanandepan", hasil_kanand);
  gerakmaju1(Belakangkanan1, Belakangkanan2, Belakangkanan3, Belakangkiri1, Belakangkiri2, Belakangkiri3, Depankiri1, Depankiri2, Depankiri3, Depankanan1, Depankanan2, Depankanan3, hasil_kananb, hasil_kirib, hasil_kirid, hasil_kanand, pos);

  transformasi(-110,0,0,"kananbelakang", hasil_kananb);
  transformasi(-55,0,0,"kiribelakang", hasil_kirib);
  transformasi(55,0,0,"kiridepan", hasil_kirid);
  transformasi(0,0,0,"kanandepan", hasil_kanand);
  gerakmaju1(Belakangkanan1, Belakangkanan2, Belakangkanan3, Belakangkiri1, Belakangkiri2, Belakangkiri3, Depankiri1, Depankiri2, Depankiri3, Depankanan1, Depankanan2, Depankanan3, hasil_kananb, hasil_kirib, hasil_kirid, hasil_kanand, pos);

}

void majuSemua(){
  maju();
  maju2();
  maju3();
}

void coba(){
  //  transformasi(0,0,0,"kananbelakang", hasil_kananb);
  // transformasi(0,0,0,"kiribelakang", hasil_kirib);
  // transformasi(0,0,0,"kiridepan", hasil_kirid);
  // transformasi(0,0,0,"kanandepan", hasil_kanand);
  // gerakmaju1(Belakangkanan1, Belakangkanan2, Belakangkanan3, Belakangkiri1, Belakangkiri2, Belakangkiri3, Depankiri1, Depankiri2, Depankiri3, Depankanan1, Depankanan2, Depankanan3, hasil_kananb, hasil_kirib, hasil_kirid, hasil_kanand, pos);
 
  //putarkanan
  transformasi(-55,0,0,"kananbelakang", hasil_kananb);
  transformasi(-55,0,0,"kiribelakang", hasil_kirib);
  transformasi(55,0,0,"kiridepan", hasil_kirid);
  transformasi(55,0,0,"kanandepan", hasil_kanand);
  gerakmaju1(Belakangkanan1, Belakangkanan2, Belakangkanan3, Belakangkiri1, Belakangkiri2, Belakangkiri3, Depankiri1, Depankiri2, Depankiri3, Depankanan1, Depankanan2, Depankanan3, hasil_kananb, hasil_kirib, hasil_kirid, hasil_kanand, pos);

  transformasi(-55,0,0,"kananbelakang", hasil_kananb);
  transformasi(-55,0,0,"kiribelakang", hasil_kirib);
  transformasi(55,0,70,"kiridepan", hasil_kirid);
  transformasi(55,0,0,"kanandepan", hasil_kanand);
  gerakmaju1(Belakangkanan1, Belakangkanan2, Belakangkanan3, Belakangkiri1, Belakangkiri2, Belakangkiri3, Depankiri1, Depankiri2, Depankiri3, Depankanan1, Depankanan2, Depankanan3, hasil_kananb, hasil_kirib, hasil_kirid, hasil_kanand, pos);
  transformasi(-55,0,0,"kananbelakang", hasil_kananb);
  transformasi(-55,0,0,"kiribelakang", hasil_kirib);
  transformasi(120,-100,0,"kiridepan", hasil_kirid);
  transformasi(55,0,0,"kanandepan", hasil_kanand);
  gerakmaju1(Belakangkanan1, Belakangkanan2, Belakangkanan3, Belakangkiri1, Belakangkiri2, Belakangkiri3, Depankiri1, Depankiri2, Depankiri3, Depankanan1, Depankanan2, Depankanan3, hasil_kananb, hasil_kirib, hasil_kirid, hasil_kanand, pos);
  transformasi(-55,0,0,"kananbelakang", hasil_kananb);
  transformasi(-55,0,0,"kiribelakang", hasil_kirib);
  transformasi(120,-100,0,"kiridepan", hasil_kirid);
  transformasi(55,0,70,"kanandepan", hasil_kanand);
  gerakmaju1(Belakangkanan1, Belakangkanan2, Belakangkanan3, Belakangkiri1, Belakangkiri2, Belakangkiri3, Depankiri1, Depankiri2, Depankiri3, Depankanan1, Depankanan2, Depankanan3, hasil_kananb, hasil_kirib, hasil_kirid, hasil_kanand, pos);
  transformasi(-55,0,0,"kananbelakang", hasil_kananb);
  transformasi(-55,0,0,"kiribelakang", hasil_kirib);
  transformasi(120,-100,0,"kiridepan", hasil_kirid);
  transformasi(0,0,0,"kanandepan", hasil_kanand);
  gerakmaju1(Belakangkanan1, Belakangkanan2, Belakangkanan3, Belakangkiri1, Belakangkiri2, Belakangkiri3, Depankiri1, Depankiri2, Depankiri3, Depankanan1, Depankanan2, Depankanan3, hasil_kananb, hasil_kirib, hasil_kirid, hasil_kanand, pos);
  transformasi(-55,0,70,"kananbelakang", hasil_kananb);
  transformasi(-55,0,0,"kiribelakang", hasil_kirib);
  transformasi(120,-100,0,"kiridepan", hasil_kirid);
  transformasi(0,0,0,"kanandepan", hasil_kanand);
  gerakmaju1(Belakangkanan1, Belakangkanan2, Belakangkanan3, Belakangkiri1, Belakangkiri2, Belakangkiri3, Depankiri1, Depankiri2, Depankiri3, Depankanan1, Depankanan2, Depankanan3, hasil_kananb, hasil_kirib, hasil_kirid, hasil_kanand, pos);
  transformasi(-120,-100,0,"kananbelakang", hasil_kananb);
  transformasi(-55,0,0,"kiribelakang", hasil_kirib);
  transformasi(120,-100,0,"kiridepan", hasil_kirid);
  transformasi(0,0,0,"kanandepan", hasil_kanand);
  gerakmaju1(Belakangkanan1, Belakangkanan2, Belakangkanan3, Belakangkiri1, Belakangkiri2, Belakangkiri3, Depankiri1, Depankiri2, Depankiri3, Depankanan1, Depankanan2, Depankanan3, hasil_kananb, hasil_kirib, hasil_kirid, hasil_kanand, pos);
  transformasi(-120,-100,0,"kananbelakang", hasil_kananb);
  transformasi(-55,0,70,"kiribelakang", hasil_kirib);
  transformasi(120,-100,0,"kiridepan", hasil_kirid);
  transformasi(0,0,0,"kanandepan", hasil_kanand);
  gerakmaju1(Belakangkanan1, Belakangkanan2, Belakangkanan3, Belakangkiri1, Belakangkiri2, Belakangkiri3, Depankiri1, Depankiri2, Depankiri3, Depankanan1, Depankanan2, Depankanan3, hasil_kananb, hasil_kirib, hasil_kirid, hasil_kanand, pos);
  transformasi(-120,-100,0,"kananbelakang", hasil_kananb);
  transformasi(0,0,0,"kiribelakang", hasil_kirib);
  transformasi(120,-100,0,"kiridepan", hasil_kirid);
  transformasi(0,0,0,"kanandepan", hasil_kanand);
  gerakmaju1(Belakangkanan1, Belakangkanan2, Belakangkanan3, Belakangkiri1, Belakangkiri2, Belakangkiri3, Depankiri1, Depankiri2, Depankiri3, Depankanan1, Depankanan2, Depankanan3, hasil_kananb, hasil_kirib, hasil_kirid, hasil_kanand, pos);
  transformasi(-120,-100,0,"kananbelakang", hasil_kananb);
  transformasi(0,0,0,"kiribelakang", hasil_kirib);
  transformasi(120,-100,0,"kiridepan", hasil_kirid);
  transformasi(0,0,0,"kanandepan", hasil_kanand);
  gerakmaju1(Belakangkanan1, Belakangkanan2, Belakangkanan3, Belakangkiri1, Belakangkiri2, Belakangkiri3, Depankiri1, Depankiri2, Depankiri3, Depankanan1, Depankanan2, Depankanan3, hasil_kananb, hasil_kirib, hasil_kirid, hasil_kanand, pos);
 

  //putarkiri
//  transformasi(-55,0,0,"kananbelakang", hasil_kananb);
//  transformasi(-55,0,0,"kiribelakang", hasil_kirib);
//  transformasi(55,0,0,"kiridepan", hasil_kirid);
//  transformasi(55,0,40,"kanandepan", hasil_kanand);
//  gerakmaju1(Belakangkanan1, Belakangkanan2, Belakangkanan3, Belakangkiri1, Belakangkiri2, Belakangkiri3, Depankiri1, Depankiri2, Depankiri3, Depankanan1, Depankanan2, Depankanan3, hasil_kananb, hasil_kirib, hasil_kirid, hasil_kanand, pos);
//  transformasi(-55,0,0,"kananbelakang", hasil_kananb);
//  transformasi(-55,0,0,"kiribelakang", hasil_kirib);
//  transformasi(55,0,0,"kiridepan", hasil_kirid);
//  transformasi(120,-100,0,"kanandepan", hasil_kanand);
//  gerakmaju1(Belakangkanan1, Belakangkanan2, Belakangkanan3, Belakangkiri1, Belakangkiri2, Belakangkiri3, Depankiri1, Depankiri2, Depankiri3, Depankanan1, Depankanan2, Depankanan3, hasil_kananb, hasil_kirib, hasil_kirid, hasil_kanand, pos);
//  transformasi(-55,0,0,"kananbelakang", hasil_kananb);
//  transformasi(-55,0,0,"kiribelakang", hasil_kirib);
//  transformasi(55,0,40,"kiridepan", hasil_kirid);
//  transformasi(120,-100,0,"kanandepan", hasil_kanand);
//  gerakmaju1(Belakangkanan1, Belakangkanan2, Belakangkanan3, Belakangkiri1, Belakangkiri2, Belakangkiri3, Depankiri1, Depankiri2, Depankiri3, Depankanan1, Depankanan2, Depankanan3, hasil_kananb, hasil_kirib, hasil_kirid, hasil_kanand, pos);
//  transformasi(-55,0,0,"kananbelakang", hasil_kananb);
//  transformasi(-55,0,0,"kiribelakang", hasil_kirib);
//  transformasi(0,0,0,"kiridepan", hasil_kirid);
//  transformasi(120,-100,0,"kanandepan", hasil_kanand);
//  gerakmaju1(Belakangkanan1, Belakangkanan2, Belakangkanan3, Belakangkiri1, Belakangkiri2, Belakangkiri3, Depankiri1, Depankiri2, Depankiri3, Depankanan1, Depankanan2, Depankanan3, hasil_kananb, hasil_kirib, hasil_kirid, hasil_kanand, pos);
//  transformasi(-55,0,0,"kananbelakang", hasil_kananb);
//  transformasi(-55,0,40,"kiribelakang", hasil_kirib);
//  transformasi(0,0,0,"kiridepan", hasil_kirid);
//  transformasi(120,-100,0,"kanandepan", hasil_kanand);
//  gerakmaju1(Belakangkanan1, Belakangkanan2, Belakangkanan3, Belakangkiri1, Belakangkiri2, Belakangkiri3, Depankiri1, Depankiri2, Depankiri3, Depankanan1, Depankanan2, Depankanan3, hasil_kananb, hasil_kirib, hasil_kirid, hasil_kanand, pos);
//  transformasi(-55,0,0,"kananbelakang", hasil_kananb);
//  transformasi(-120,-100,0,"kiribelakang", hasil_kirib);
//  transformasi(0,0,0,"kiridepan", hasil_kirid);
//  transformasi(120,-100,0,"kanandepan", hasil_kanand);
//  gerakmaju1(Belakangkanan1, Belakangkanan2, Belakangkanan3, Belakangkiri1, Belakangkiri2, Belakangkiri3, Depankiri1, Depankiri2, Depankiri3, Depankanan1, Depankanan2, Depankanan3, hasil_kananb, hasil_kirib, hasil_kirid, hasil_kanand, pos);
//  transformasi(-55,0,40,"kananbelakang", hasil_kananb);
//  transformasi(-120,-100,0,"kiribelakang", hasil_kirib);
//  transformasi(0,0,0,"kiridepan", hasil_kirid);
//  transformasi(120,-100,0,"kanandepan", hasil_kanand);
//  gerakmaju1(Belakangkanan1, Belakangkanan2, Belakangkanan3, Belakangkiri1, Belakangkiri2, Belakangkiri3, Depankiri1, Depankiri2, Depankiri3, Depankanan1, Depankanan2, Depankanan3, hasil_kananb, hasil_kirib, hasil_kirid, hasil_kanand, pos);
//  transformasi(0,0,0,"kananbelakang",hasil_kananb);
//  transformasi(-120,-100,0,"kiribelakang", hasil_kirib);
//  transformasi(0,0,0,"kiridepan", hasil_kirid);
//  transformasi(120,-100,0,"kanandepan", hasil_kanand);
//  gerakmaju1(Belakangkanan1, Belakangkanan2, Belakangkanan3, Belakangkiri1, Belakangkiri2, Belakangkiri3, Depankiri1, Depankiri2, Depankiri3, Depankanan1, Depankanan2, Depankanan3, hasil_kananb, hasil_kirib, hasil_kirid, hasil_kanand, pos);
//  transformasi(0,0,0,"kananbelakang",hasil_kananb);
//  transformasi(-120,-100,0,"kiribelakang", hasil_kirib);
//  transformasi(0,0,0,"kiridepan", hasil_kirid);
//  transformasi(120,-100,0,"kanandepan", hasil_kanand);
//  gerakmaju1(Belakangkanan1, Belakangkanan2, Belakangkanan3, Belakangkiri1, Belakangkiri2, Belakangkiri3, Depankiri1, Depankiri2, Depankiri3, Depankanan1, Depankanan2, Depankanan3, hasil_kananb, hasil_kirib, hasil_kirid, hasil_kanand, pos);

}

void mencoba(){
  transformasi(-55,0,0,"kananbelakang", hasil_kananb);
  transformasi(-55,0,0,"kiribelakang", hasil_kirib);
  transformasi(55,0,0,"kiridepan", hasil_kirid);
  transformasi(55,0,0,"kanandepan", hasil_kanand);
  gerakmaju1(Belakangkanan1, Belakangkanan2, Belakangkanan3, Belakangkiri1, Belakangkiri2, Belakangkiri3, Depankiri1, Depankiri2, Depankiri3, Depankanan1, Depankanan2, Depankanan3, hasil_kananb, hasil_kirib, hasil_kirid, hasil_kanand, pos);

  transformasi(-55,0,70,"kananbelakang", hasil_kananb);
  transformasi(-55,0,0,"kiribelakang", hasil_kirib);
  transformasi(120,-100,0,"kiridepan", hasil_kirid);
  transformasi(0,0,0,"kanandepan", hasil_kanand);
  gerakmaju1(Belakangkanan1, Belakangkanan2, Belakangkanan3, Belakangkiri1, Belakangkiri2, Belakangkiri3, Depankiri1, Depankiri2, Depankiri3, Depankanan1, Depankanan2, Depankanan3, hasil_kananb, hasil_kirib, hasil_kirid, hasil_kanand, pos);
  transformasi(-120,-100,0,"kananbelakang", hasil_kananb);
  transformasi(-55,0,0,"kiribelakang", hasil_kirib);
  transformasi(120,-100,0,"kiridepan", hasil_kirid);
  transformasi(0,0,0,"kanandepan", hasil_kanand);
  gerakmaju1(Belakangkanan1, Belakangkanan2, Belakangkanan3, Belakangkiri1, Belakangkiri2, Belakangkiri3, Depankiri1, Depankiri2, Depankiri3, Depankanan1, Depankanan2, Depankanan3, hasil_kananb, hasil_kirib, hasil_kirid, hasil_kanand, pos);

}
