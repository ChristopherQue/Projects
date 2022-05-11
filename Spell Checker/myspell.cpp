// myspell.cpp

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "hashtable.h"

using namespace std;
using namespace cop4530;

void menu()
{
	cout << "\n\n";
	cout << "l - Load Dictionary From File" << endl;
	cout << "a - Add Word" << endl;
	cout << "r - Remove Word" << endl;
	cout << "c - Clear HashTable" << endl;
	cout << "f - Find Word" << endl;
	cout << "d - Dump HashTable" << endl;
	cout << "s - HashTable Size" << endl;
	cout << "w - Write to File" << endl;
	cout << "x - Exit program" << endl;
	cout << "\nEnter choice : ";
}

void noSpace() {
	char space;
	while(isspace(cin.peek()) && !cin.eof())
		cin.get(space);
}

int main() {

  HashTable<string> dict;
  int capacity;
	char choice;

	cout << "Enter the preferred hash table capacity: ";
	cin >> capacity;
  if(capacity <= 0)
	  capacity = 11;

  do {
  	menu();
		cin >> choice;

		if(tolower(choice) == 'l') {
			cout << "I was not able to properly complete this function.\n";
			// string filename;
			// cout << "Enter dictionary filename to load from: ";
			// noSpace();
			// getline(cin, filename);
	 		// if(!dict.load(filename.c_str()))
			// 	cout << "Unable to open file: " << filename << '\n';
			// else
			//   cout << "Dictionary loaded successfully.\n";

		}

		if(tolower(choice) == 'a') {
			string input;
			cout << "Enter word: ";
			noSpace();
			getline(cin, input);
			if(!dict.contains(input)) {
			  dict.insert(input);
				cout << "Word: " << input << " has been added.\n";
			}
			else
			  cout << input << " is already in the dictionary. \n";
		}

		if(tolower(choice) == 'r') {
			string word;
	    cout << "Enter word: ";
			noSpace();
			getline( cin, word );
			if(dict.remove(word))
				cout << "Word " << word << " has been deleted.\n";
			else
				cout << "Word " << word << " not found. Deletion failed.\n";
		}

		if(tolower(choice) == 'c') {
			dict.clear();
			cout << "Hashtable has been cleared.\n";
		}

		if(tolower(choice) == 'f') {
			string word;
			cout << "Enter a word: ";
			noSpace();
			getline(cin, word);
			if(dict.contains(word))
			  cout << "Word " << word << " found.\n";
			else
			  cout << "Word " << word << " not found.\n";
		}

		if(tolower(choice) == 'd') { // outputs everything
			dict.dump();
		}

		if(tolower(choice) == 's') {
			cout << "Size of hashtable: " << dict.getSize() << endl;
		}

		if(tolower(choice) == 'w') {
			cout << "I was not able to properly complete this function.\n";
			// string outFile;
			// cout << "Enter output file name to write to: ";
			// noSpace();
			// getline(cin, outFile);
			// dict.write_to_file(outFile.c_str());
		}

  } while(tolower(choice) != 'x');

	cout << "Program Terminating... \n\n";
	return 0;
}
