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
    string temp;
    bool inside = false;

    while (getline(cin, line)) {

	    list = split(line, ' ');
      for (int i = 0; i < list.size(); i++) {
        temp = list[i];
        for (int i = 0; i < fullList.size(); i++) {
          if (temp == fullList[i])
            inside = true;
          else
            inside = false;
          if (inside == false)
            fullList.push_back(temp);
        }
        // if (inside == false)
        //   fullList.push_back(temp);
        // fullList.push_back(temp);
      }
      list.clear();

    }

    print(fullList);

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
