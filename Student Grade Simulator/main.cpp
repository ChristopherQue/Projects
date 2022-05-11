// Chris Que
// Course: COP3330
// Section: 0006
// Project number: 6
// Summary: this is the main file that implements the usage of both student
// and studentlist files and makes a menu function that loops until the
// user at the keyboard decides to end the program. 

//--------MAIN.CPP

#include "student.h"
#include "studentlist.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <iomanip>

using namespace std;

void showMenu();
char getSelection();

int main() {
  char menu;
  StudentList s;
  char file[31];


  showMenu();
  do {
    menu = getSelection();
    switch(menu) {
      case 'I': cout << "Enter the file name: ";
                s.ImportFile(file);
        break;
      case 'S': s.ShowList();
        break;
      case 'E': cout << "Enter the export file name: ";
                s.CreateReportFile(file);
        break;
      case 'M': showMenu();
        break;
      case 'Q':
        break;
    }
  } while(toupper(menu) != 'Q');

  cout << "Exiting program\n";

  return 0;
}

void showMenu() {
  cout << endl;
  cout << "            *** Student List Menu *** \n";
  cout << "     I:     Import students from a file \n";
  cout << "     S:     Show student list (brief) \n";
  cout << "     E:     Export a grade report (to file) \n";
  cout << "     M:     Show this Menu \n";
  cout << "     Q:     Quit Program  \n";
}

bool valid(char m) {
  return ((m == 'I') || (m == 'S') || (m == 'E') || (m == 'M') ||
          (m == 'Q'));
}  // menu valid checker

char menuSelection() {
  char selection;
  cout << "\n> ";
  cin >> selection;
  selection = toupper(selection);
  return selection;
}

char getSelection() {
  char selection = menuSelection();
  while(!valid(selection)) {  // menu data checker
    cout << "\nInvalid menu option, please try again: \n";
    selection = menuSelection();
  }
  return selection;
}
