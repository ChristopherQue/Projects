#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

vector<string> split(const string &str, const char chr);
void print(const vector<string>& vec);

int main() {

    vector<string> list;
    vector<string> fullList;
    string line;
    int bList = 0; // big list tracker to add all elements

    while (getline(cin, line)) {
	    list = split(line, ' ');
      for (int i = 0; i < list.size(); i++) {
        fullList[bList] = list[i];
        bList++;
      }
      list.clear();
    }
    print(list);


    return 0;
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

void print(const vector<string>& vec) { // used to be template int

    for (int i = 0; i < vec.size(); i++)
      cout << vec[i] << endl;

}
