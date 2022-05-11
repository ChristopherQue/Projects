// Chris Que
// Course: COP3330
// Section: 0006
// Project number: 6
// Summary: the .h file for the list of pointers to students. contains the
// import and export functions that allow the user to enter a file to be
// read, and a file to be exported.

//--------STUDENTLIST.H

#include "student.h"

class StudentList
{
public:
   StudentList();		// starts out empty
   ~StudentList();		// cleanup (destructor)

   bool ImportFile(const char* filename);
   bool CreateReportFile(const char* filename);
   void ShowList() const;	// print basic list data
   void Grow();
   char GetGrade(double grade);

private:
  Student** sList;   // array of pointers to student list
  int currentSize;
  int size;


};
