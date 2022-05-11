// Chris Que
// Course: COP3330
// Section: 0006
// Project number: 6
// Summary: this is the .cpp file for the definitions of the student class
// and the derived classes. This has the getters and all of the constructors
// for each class.

//------- STUDENT.CPP

#include "student.h"
#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

// student class member functions *********
Student:: Student() {       // empty default student
  firstName = " ";
  lastName = " ";
  course = " ";
}

Student:: Student(string fn, string ln, string crse) {
  firstName = fn;
  lastName = ln;
  course = crse;
}

string Student:: GetfirstName() const {
  return firstName;
}

string Student:: GetName() const {
  return firstName + ' ' + lastName;
}

string Student:: GetlastName() const {
  return lastName;
}

string Student:: GetCourse() const {
  return course;
}

void Student:: printShort() {
  cout << setw(20) << left << lastName;
  cout << setw(21) << firstName;
  cout << setw(10) << left << course << endl;
}

// end of student member functions ********

// biology student member functions *******

biologyStudent:: biologyStudent() {
  labGrade = 0;
  btest1 = 0;
  btest2 = 0;
  btest3 = 0;
  bfinalExam = 0;
}

biologyStudent:: biologyStudent(string fn, string ln, string crse, int lg,
                int bt1, int bt2, int bt3, int bfin) : Student(fn, ln, crse) {
  labGrade = lg;
  btest1 = bt1;
  btest2 = bt2;
  btest3 = bt3;
  bfinalExam = bfin;
}

double biologyStudent:: average() const {
  double testavg = (btest1 + btest2 + btest3) * .15;
  double labperc = (labGrade * .30);
  double finalperc = (bfinalExam * .25);
  cout << fixed << showpoint << setprecision(2);
  return (testavg + labperc + finalperc); // 2 decimal precision
}

int biologyStudent:: GetLab() const {
  return labGrade;
}

int biologyStudent:: Gettest1() const {
  return btest1;
}

int biologyStudent:: Gettest2() const {
  return btest2;
}

int biologyStudent:: Gettest3() const {
  return btest3;
}

int biologyStudent:: GetFinal() const {
  return bfinalExam;
}

void biologyStudent:: printShort() {
  Student:: printShort();
}

// end of bio member functions ************

// theater student member functions *******

theaterStudent:: theaterStudent() {
  participation = 0;
  midterm = 0;
  thfinalExam = 0;
}

theaterStudent:: theaterStudent(string fn, string ln, string crse,
                                   int prt, int mdt, int tfin) : Student(fn, ln, crse) {
  participation = prt;
  midterm = mdt;
  thfinalExam = tfin;
}

double theaterStudent:: average () const {
  double partic = participation * .40;
  double mid = midterm * .25;
  double fin = thfinalExam * .35;
  cout << fixed << showpoint << setprecision(2);
  return (fin + partic + mid);
}

int theaterStudent:: GetParticipation() const{
  return participation;
}    // participation 40%

int theaterStudent::GetMid() const {
  return midterm;
}        // midterm 25%


int theaterStudent:: GetFinal() const {
  return thfinalExam;
}

void theaterStudent:: printShort() {
  Student:: printShort();
}

// end theater member funcs ***************

// comp sci member functions **************

compSciStudent::compSciStudent() {
  p1 = 0;
  p2 = 0;
  p3 = 0;
  p4 = 0;
  p5 = 0;
  p6 = 0;
  cstest1 = 0;
  cstest2 = 0;
  csfinalExam = 0;
}

compSciStudent:: compSciStudent(string fn, string ln, string crse, int pr1,
                                   int pr2, int pr3, int pr4, int pr5, int pr6,
                                   int ts1, int tes2, int fins) : Student(fn, ln, crse) {
  p1 = pr1;
  p2 = pr2;
  p3 = pr3;
  p4 = pr4;
  p5 = pr5;
  p6 = pr6;
  cstest1 = ts1;
  cstest2 = tes2;
  csfinalExam = fins;
}

double compSciStudent::average() const {
  double programAverage = ((p1 + p2 + p3 + p4 + p5 + p6) / 6.0) * .30;
  double test1perc = cstest1 * .20;
  double test2perc = cstest2 * .20;
  double finalpercent = csfinalExam * .30;
  // finalGrade = (programAverage + testaverage + finalpercent);
  cout << fixed << showpoint << setprecision(2);
  return (programAverage + test1perc + test2perc + finalpercent);
}     // calculate and return final grade

int compSciStudent::Getp1() const {
  return p1;
}

int compSciStudent::Getp2() const {
  return p2;
}

int compSciStudent::Getp3() const {
  return p3;
}

int compSciStudent::Getp4() const {
  return p4;
}

int compSciStudent::Getp5() const {
  return p5;
}

int compSciStudent::Getp6() const {
  return p6;
}

int compSciStudent::Gettest1() const {
  return cstest1;
}

int compSciStudent::Gettest2() const {
return cstest2;
}

int compSciStudent:: GetFinal() const {
  return csfinalExam;
}

void compSciStudent:: printShort() {
  Student:: printShort();
}

// end of cs member funcs *****************
