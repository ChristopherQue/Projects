#include <string>
#include <algorithm>
#include <iostream>
#include "Stack.h"

using namespace std;
using namespace cop4530;

int postfix_calc(string exp);
string infix2postfix(string exp);
int precedence(char sign);

int main() {

  string input, post, temp;

  cout << "****************\n";
  cout << "* CHRIS' OUTPUT*\n";
  cout << "****************\n\n";
  cout << "Calculating infix expressions: \n\n";

  do {
    cout << "Enter an infix expression, or \"quit\" to exit.\n";
    cout << "infix exp: ";
    getline(cin, input);
    input.erase(remove_if(input.begin(), input.end(), ::isspace), input.end());
    if (input == "quit") {
      cout << "\nprogram is being terminated\n\n";
    }
    else {
      post = infix2postfix(input); // insert post fix notation plus solution below
      temp = post;  // temporary store to allow postfix_calc to use string
      temp.erase(remove_if(temp.begin(), temp.end(), ::isspace), temp.end());
      cout << "postfix exp: " << post << "= " << postfix_calc(temp) << endl << endl;
    }
  } while(input != "quit");

  return 0;

}

int postfix_calc(string exp) {
    Stack<int> calc;
    int first, second;
    for (int i = 0; i < exp.length(); ++i) {
      if ('0' <= exp[i] && exp[i] <= '9') {
        calc.push( exp[i] - '0');
      }
      else {  // uses the top 2 ints and performs operation on them
        first = calc.top();
        calc.pop();
        second = calc.top();
        calc.pop();
        switch (exp[i]) {  // operates based on what the sign is
          case '+':
            calc.push(second + first);
            break;
          case '-':
            calc.push(second - first);
            break;
          case '*':
            calc.push(second * first);
            break;
          case '/':
            calc.push(second / first);
            break;
        }
      }
    }
    return calc.top();
}

string infix2postfix(string exp) {

   Stack<char> st;
   string result, final;

   for(int i = 0; i < exp.length(); ++i) {
     char c = exp[i];
     if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
       result += c;  // if it is an operand
     else if(c == '(')
       st.push('(');
     else if(c == ')') {
       while(st.top() != '(') {
         result += st.top();
         st.pop();
       }
       st.pop();
     }
     else { // if it is an operator
       while(!st.empty() && precedence(exp[i]) <= precedence(st.top())) {
         result += st.top();
         st.pop();
       }
       st.push(c);
     }
   }
   while(!st.empty()) {
       result += st.top();
       st.pop();
   }
   // cout << "testing result: " << result << endl; // testing
   for (int i = 0; i < result.length(); ++i) {
     final += result[i];
     final += ' ';
   }
   return final;

}

int precedence(char sign) {
	if(sign == '*' || sign == '/')
		return (3);
	else if(sign == '+' || sign == '-')
		return (2);
  else if(sign == ' ')
    return (1);
	else
	  return (0);
}
