#include <string>
#include <cstring>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

void print(const vector<string>& vec);
vector<string> split(const string &s, const char c);

int main() {

  string input;       // information being read in
  vector<string> seventh;  // for 7th field
  vector<string> cleaned;  // final cleaned information
  vector<string> single;    // individual AS numbers
  string temp;
  string clnd_sev;   // for no duplicates and cleaned

  while (getline(cin, input)) {

    seventh = split(input, '|');
    temp = seventh[6];    // store into a string then push it into vector
    temp.erase(remove(temp.begin(), temp.end(), '['), temp.end());   // deletes bracket
    temp.erase(remove(temp.begin(), temp.end(), ']'), temp.end());   // deletes bracket
    single = split(temp, ' ');

    single.erase(unique(single.begin(), single.end()), single.end());  // deleted repeated values

    for (int i = 0; i < single.size(); i++) {  // puts it back into one line
      string temp;
      temp = single[i];
      clnd_sev.append(temp);
      clnd_sev.append(" ");
    }
    cleaned.push_back(clnd_sev);
    clnd_sev.clear();
  }

  print(cleaned);  // prints vector
  // cout << "Vector Size: " << cleaned.size() << endl;  // for testing size

  return 0;

}

void print(const vector<string>& vec) { // used to be template int

    for (int i = 0; i < vec.size(); i++)
      cout << vec[i] << endl;

}

vector<string> split(const string &str, const char chr) {

  string sevth;
  vector<string> vect;

  istringstream ss(str);
  while (getline(ss, sevth, chr)) {
    vect.push_back(sevth);
  }
	return vect;

}
