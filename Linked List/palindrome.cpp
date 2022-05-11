#include "stack.h"
#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

int main () {

  Stack <char> charStack;
  char input[100];
  int size, check;
  char popChar;

  cout << "\n*** Welcome to the Palindrome detector ***\n\n";

  cout << "Please enter a string: \n";
  cout << "> ";
  cin.getline(input, 100, '\n');

  size = strlen(input); // check for the correct size of only letters

  for (int i = 0; i < size; i++) { // storing into stack
    char temp = input[i];
    if (isalpha(temp))
      charStack.push(tolower(temp));
  }

  while (!charStack.isStackEmpty()) {
    charStack.pop(popChar);
    int i;
    if (isalpha(input[i])) {
      if (popChar != tolower(input[i]))
        check++;       // if it is not a palindrome it will mark it
      i++;
    }
  }

  if (check > 0)
    cout << endl << '"' << input << '"' << " is NOT a palindrome. \n\n";
  else
    cout << endl << '"' << input << '"' << " IS a palindrome. \n\n";

  return 0;
}
