#include "println.hpp"

// ================ Array ================

#define BUFFER_SIZE 1024

void demoArray(){
  int buffer[BUFFER_SIZE];
  buffer[0] = 0;
  buffer[BUFFER_SIZE-1] = 0;
}

// ================ Struct ================

struct Date {
  int day;
  int month;
  int year;
};

void demoStruct(){
  Date EinsteinsBirthday = {14, 03, 1879};
  int EinsteinsBirthYear = EinsteinsBirthday.year;
  println("EinsteinsBirthYear = " , EinsteinsBirthYear);
}

// ================ Array and Struct ================


struct DateWithMon {
  int day;
  int month;
  int year;
  char mon[4];
};

void combined(){
  DateWithMon EinsteinsBirthday = {14, 03, 1879, {'M', 'a', 'r', 0}};
  /*EinsteinsBirthday.mon[0] = 'M';
  EinsteinsBirthday.mon[1] = 'a';
  EinsteinsBirthday.mon[2] = 'r';
  EinsteinsBirthday.mon[3] = 0;*/

  DateWithMon EulersBirthday = {15, 04, 1707, {'A', 'p', 'r', 0}};

  DateWithMon importantBirthdays[2]; // array of structs
  importantBirthdays[0] = EinsteinsBirthday;
  importantBirthdays[1] = EulersBirthday;

  println("importantBirthdays[0].year = " , importantBirthdays[0].year, " mon = ", importantBirthdays[0].mon);
  println("importantBirthdays[1].year = " , importantBirthdays[1].year, " mon = ", importantBirthdays[1].mon);
}

// ================ main ================

int main(){
  demoArray();
  demoStruct();
  combined();
  return 0;
}

