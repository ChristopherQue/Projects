// Chris Que
// Course: COP3330
// Section: 0006
// Project number: 6
// Summary:  this is the .h that contains the prototypes for the base classes
// student, and the derived classes biology theater and compsci student
// It contains virtual functions in the base class that is used when
// the derived classes need to use the same function

// ------------ STUDENT.H ------------------


#include <string>
using namespace std;

#ifndef _STUDENT_
#define _STUDENT_

class Student {       // for information common to all students

public:
  Student();      // default constructor
  Student(string fn, string ln, string crse);
  // maybe add constructor with more parameters
  virtual double average() const = 0;   // pure virtual with no definition
  // if there is a print function neeeded for all classes
  string GetfirstName() const;
  string GetName() const;
  string GetlastName() const;
  string GetCourse() const;
  virtual void printShort();  // change name to print
  virtual int GetFinal() const = 0;

private:
  string numberStudents;

protected:
  string firstName;
  string lastName;
  string course;

};

class biologyStudent: public Student {

public:
  biologyStudent();
  biologyStudent(string fn, string ln, string crse, int lg, int bt1, int bt2,
                    int bt3, int bfin);
  double average() const;     // calculate and return final grade
  // add default constructor
  // add constructor with parameters

  // accessors
  int GetLab() const;
  int Gettest1() const;
  int Gettest2() const;
  int Gettest3() const;
  //int GetbFinalEx() const;
  int GetFinal() const;
  void printShort();

private:    // things only applicable to bio student
  int labGrade;    // lab grade 30%
  int btest1;      // three term tests 15%
  int btest2;
  int btest3;
  int bfinalExam;         // final exam 25%
  double bfinalGrade;     // final grade:

};

class theaterStudent: public Student {

public:
  theaterStudent();
  theaterStudent(string fn, string ln, string crse, int prt, int mdt, int tfin);
  // make a constructor with different parameters
  double average() const;     // calculate and return final grade
  int GetParticipation() const;    // participation 40%
  int GetMid() const;          // midterm 25%
  int GetthFinalEx() const;        // final exam 35%
  int GetFinal() const;
  void printShort();

private:
  int participation;    // participation 40%
  int midterm;          // midterm 25%
  int thfinalExam;        // final exam 35%
  double thfinalGrade;    // final grade:

};

class compSciStudent: public Student {

public:
  compSciStudent();
  compSciStudent(string fn, string ln, string crse, int pr1, int pr2, int pr3,
                    int pr4, int pr5, int pr6, int ts1, int tes2, int fins);

  // make a constructor with parameters
  double average() const;     // calculate and return final grade
  // accessors
  int Getp1() const;
  int Getp2() const;
  int Getp3() const;
  int Getp4() const;
  int Getp5() const;
  int Getp6() const;
  int Gettest1() const;
  int Gettest2() const;
  int GetFinal() const;
  void printShort();
  char printGrade();

private:
  int p1;
  int p2;
  int p3;
  int p4;
  int p5;
  int p6;
  int cstest1;
  int cstest2;
  int csfinalExam;
  // 6 programming assignments to be averaged (decimal number)
  double finalGrade;           // final grade:
  double programAverage;       // -  program average 30%
  // -  test 1 20% test 2 20% final exam 30%


};

#endif
