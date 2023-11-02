/* Splitting Strings by Using strtok() or vector<string> */

#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;


int main(int argc, char* argv[]){

    string str ="; ,the-: quick- -\tbrown: ;, fox, \t jumps over; :the ,,lazy   dog- ";
    auto tok = ".,:;- \t";

    //////////////////////////////////

    int length = str.length();
    char *arr = new char[length+1];                 // Dynamic Char Array with the Length of the Given String
    strcpy(arr, str.c_str());                       // Copying the Given String to the Dynamic Char Array "arr"

    int wordcount = 0;                              // Number of Clean Words That will Be Extracted from the Array
    char *pch = strtok(arr, tok);                   // Getting the First Word from "arr" Before Any of " ,;:-" Comes

    cout << endl;
    while(pch != NULL){
        cout << pch << endl;                        // Printing Each Word Before Reaching Any Token Character in "tok"
        wordcount++;                                // Counting the Clean Words That are Extracted from the Char Array
        pch = strtok(NULL, tok);                    // Continuing to Get the Next Words Before Any of " ,;:-" Comes
    }delete[] arr;                                  // Deleting the Allocated Dynamic Char Array from the Memory

    cout << endl << wordcount << " Words!" << endl << endl;


    //////////////////////////////////
    cout << "--------" << endl << endl;
    //////////////////////////////////


    vector<string> words;
    string temp = "";
    bool worder = false;

    string chars = ".,:;-";                         // The List of Odd Chars (Except Space: " ") to Remove from the Main String
    str.erase(remove_if(str.begin(), str.end(), [&chars](char &c){return chars.find(c) != string::npos;}), str.end());

    for(int i=0; i<int(str.length()); i++){
        if(str[i] != ' ' && str[i] != '\t'){        // As Long as the Read Char is Not A Space: " " and Not A Tab: "\t"
            worder = true;
            temp += str[i];                         // Extracting Clear Words Char by Char Before Reaching to Any Space: " "
        }
        else{                                       // At the First Occurrence of Any Space: " "
            if(worder){                             // If the Flag is Still True
                words.push_back(temp);              // Add the Latest Clean Word to the Vector of Words
                temp = "";                          // Reset the temp String for the Next Word
            }
            worder = false;                         // If Any Space Comes Again, do Not Add temp = "" to "words" the Next Time
        }

        if(worder && i == int(str.length())-1){     // If This is the Final Char of the String and It is Not A Space,
            words.push_back(temp);                  // Add the Latest Clean Word to the Vector Before Leaving the Loop
        }
    }


    for(auto element : words)
        cout << element << endl;

    cout << endl << words.size() << " Words!" << endl;


cout << endl << endl << "-------------" << endl;
system("pause");
return 0;
}
