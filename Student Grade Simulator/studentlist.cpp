// Chris Que
// Course: COP3330
// Section: 0006
// Project number: 6
// Summary: this file has the definitions of the prototypes from the
// corresponding .h file. has helper functions when necessary and this helps
// grow the student list as students are being read in from the file.

//--------STUDENTLIST.CPP

#include "studentlist.h"
#include "student.h"
#include <iomanip>
#include <fstream>
#include <iostream>

using namespace std;

StudentList:: StudentList() {
  size = 0;
  currentSize = 0;
  sList = new Student*[size];
}		// starts out empty
StudentList:: ~StudentList() {
  delete [] sList;    // name of the array of pointers
}		// cleanup (destructor)

bool StudentList:: ImportFile(const char* filename) {
    ifstream inFile;
    string fileName, last, first, major, shortCrse, fullCrse, ignore;
    int p1, p2, p3, p4, p5, p6, t1, t2, t3, fin, labGr, parti, midt, numstud;
    char ch;
    bool input = false;

    while(!input) {
      cin >> fileName;                   //user input for file
      inFile.open(fileName.c_str());  //opens file
      if(!inFile)                   //if file is invalid it loops
        cout << "Could not open file, please enter a vailid file name: ";
      else
        input = true;
    }
    inFile >> numstud;
    for (int i = 0; i < numstud; i++) {
      Grow();       // grow as students are imported
      inFile.ignore();    // ignore buffer
      getline(inFile, last, ',');
      inFile.ignore();
      getline(inFile, first, '\n');
      inFile >> shortCrse;
      // cout << "short course: " << shortCrse << endl;  // testing
      if(shortCrse == "Computer") {
        fullCrse = "Computer Science";
        inFile >> ignore >> p1 >> p2 >> p3 >> p4 >> p5 >> p6 >> t1 >> t2 >> fin;
        sList[currentSize] = new compSciStudent(first, last, fullCrse, p1, p2, p3,
                                      p4, p5, p6, t1, t2, fin);
      }
      if(shortCrse == "Biology") {
        fullCrse = "Biology";
        inFile >> labGr >> t1 >> t2 >> t3 >> fin;
        sList[currentSize] = new biologyStudent(first, last, fullCrse, labGr, t1, t2, t3, fin);
      }
      if(shortCrse == "Theater") {
        fullCrse = "Theater";
        inFile >> parti >> midt >> fin;
        sList[currentSize] = new theaterStudent(first, last, fullCrse, parti, midt, fin);
      }
      currentSize++; //iteration
    }

    inFile.close();
    return true;
}

void StudentList:: Grow() {
  size = size + 1;

  Student** newStudlist = new Student*[size];

  for (int i = 0; i < size; i++)
    newStudlist[i] = sList[i];

  delete [] sList;

  sList = newStudlist;
}

bool StudentList:: CreateReportFile(const char* filename) {
  ofstream outFile;
  string fileName;
  char blank = ' ';
  char grade;
  bool input = false;
  int a, b, c, d, f;
  a = b = c = d = f = 0;

  while(!input) {
    cin >> fileName;                   //user input for file
    outFile.open(fileName.c_str());  //opens file
    if(!outFile)                   //if file is invalid it loops
      cout << "Could not open file, please enter a vailid file name: ";
    else
      input = true;
  }

    outFile << fixed << showpoint << setprecision(2);
    outFile << "Student Grade Summary\n";
    outFile << "---------------------\n\n";
    outFile << "BIOLOGY CLASS\n\n";
    outFile << "Student" << setw(28) << blank << "Final  Final   Letter\n";
    outFile << "Name" << setw(31) << blank << "Exam   Avg     Grade\n";
    outFile << "----------------------------------------------------------\n";
    for (int i = 0; i < size; i++) {
      if(sList[i]->GetCourse() == "Biology") {
        outFile << setw(35) << left << sList[i]->GetName();
        outFile << sList[i]->GetFinal() << "     ";
        outFile << sList[i]->average() << "   " << GetGrade(sList[i]->average()) << endl;
        if(GetGrade(sList[i]->average()) == 'A')
          a++;
        if(GetGrade(sList[i]->average()) == 'B')
          b++;
        if(GetGrade(sList[i]->average()) == 'C')
          c++;
        if(GetGrade(sList[i]->average()) == 'D')
          d++;
        if(GetGrade(sList[i]->average()) == 'F')
          f++;
      }
    }
    outFile << endl;
    outFile << "THEATER CLASS\n\n";
    outFile << "Student" << setw(28) << blank << "Final  Final   Letter\n";
    outFile << "Name" << setw(31) << blank << "Exam   Avg     Grade\n";
    outFile << "----------------------------------------------------------\n";
    for (int i = 0; i < size; i++) {
      if(sList[i]->GetCourse() == "Theater") {
        outFile << setw(35) << left << sList[i]->GetName();
        outFile << sList[i]->GetFinal() << "     ";
        outFile << sList[i]->average() << "   " << GetGrade(sList[i]->average()) << endl;
        if(GetGrade(sList[i]->average()) == 'A')
          a++;
        if(GetGrade(sList[i]->average()) == 'B')
          b++;
        if(GetGrade(sList[i]->average()) == 'C')
          c++;
        if(GetGrade(sList[i]->average()) == 'D')
          d++;
        if(GetGrade(sList[i]->average()) == 'F')
          f++;
      }
    }
    outFile << endl;
    outFile << "COMPSCI CLASS\n\n";
    outFile << "Student" << setw(28) << blank << "Final  Final   Letter\n";
    outFile << "Name" << setw(31) << blank << "Exam   Avg     Grade\n";
    outFile << "----------------------------------------------------------\n";
    for (int i = 0; i < size; i++) {
      if(sList[i]->GetCourse() == "Computer Science") {
        outFile << setw(35) << left << sList[i]->GetName();
        outFile << sList[i]->GetFinal() << "     ";
        outFile << sList[i]->average() << "   " << GetGrade(sList[i]->average()) << endl;
        if(GetGrade(sList[i]->average()) == 'A')
          a++;
        if(GetGrade(sList[i]->average()) == 'B')
          b++;
        if(GetGrade(sList[i]->average()) == 'C')
          c++;
        if(GetGrade(sList[i]->average()) == 'D')
          d++;
        if(GetGrade(sList[i]->average()) == 'F')
          f++;
      }
    }
    outFile << endl;
    outFile << "\nOVERALL GRADE DISTRIBUTION\n\n";
    outFile << "A:    " << a << endl;
    outFile << "B:    " << b << endl;
    outFile << "C:    " << c << endl;
    outFile << "D:    " << d << endl;
    outFile << "F:    " << f << endl << endl;

  return true;
}

void StudentList:: ShowList() const {
  cout << setw(21) << left << "Last Name ";
  cout << setw(21) << "First Name ";
  cout << setw(10) << right << "Course\n\n";
  for (int i = 0; i < size; i++)
    sList[i]->printShort();

}	// print basic list data

char StudentList:: GetGrade(double grade) {
  int a,b,c,d,f;
  char letter;
  for (int i = 0; i < size; i++) {
    if(grade > 90) {
      letter = 'A';
      a++;
    }
    else if((grade > 80) && (grade < 90)) {
        letter = 'B';
        b++;
    }
    else if((grade > 70) && (grade < 80)) {
        letter = 'C';
        c++;
    }
    else if((grade > 60) && (grade < 70)) {
        letter = 'D';
        d++;
    }
    else {
        letter = 'F';
        f++;
    }
  }
  return letter;
}
