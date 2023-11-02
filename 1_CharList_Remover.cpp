/* Removing All the Occurrences of a List of Characters in a String. */

#include <algorithm>
#include <iostream>
using namespace std;


int main(){

string input = "a- ;b -,- .: c-- :d. ,e";		// The Main Input String

cout << endl << input << endl << endl;

string chars = " .,:;-";		// The List of Characters to Remove from the Main Input String
input.erase(remove_if(input.begin(), input.end(), [&chars](char &c){return chars.find(c) != string::npos;}), input.end());

cout << input << endl;


cout << endl << endl << "-------------" << endl;
system("pause");
return 0;
}
