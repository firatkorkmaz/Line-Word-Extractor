/* Removing Specific Characters from Head and Tail of a String by Using Lambda Functions. */

#include <iostream>
using namespace std;


int main() {

    string str = "  \t  \thello world \t   ";       // The Main Input String
    string trim = " \t";                            // The List of Characters to Trim

    cout << endl << str << endl << endl;

    auto ftrim = [](string &item, string &trim){    // Lambda Function to Remove Chars from Both Head and Tail of the Main String
        int pos_s = item.find_first_not_of(trim);
        int pos_e = item.find_last_not_of(trim);
        item = item.substr(pos_s, pos_e-pos_s+1);};

    ftrim(str, trim);                               // Directly Updates the Main String with the Trimmed New Version of It

    cout << str << endl;


cout << endl << endl << "-------------" << endl;
system("pause");
return 0;
}
