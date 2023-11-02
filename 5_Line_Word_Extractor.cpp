/* Line and Word Extractor with Their Number of Occurrences */

#include <algorithm>
#include <iostream>
#include <cstring>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

typedef pair<string, int> Line;     // Line Type Defined Which will Store Pairs of String & Integer


int main(int argc, char* argv[]){

    string filename;

    if(argv[1]){             // If the Filename is Provided as An Input Argument to Run the Program
        istringstream inputfile(argv[1]);
        inputfile >> filename;
    }
    else{	                                // If The Filename is Not Provided as An Input Argument
        cout << "Enter the Filename to Read: ";               //  Ask the User to Enter It Manually
        cin >> filename;
    }

    cout << endl;

    ifstream infile(filename);
    if(!infile){                             // If There is No Test File with the Entered File Name
        cout << "There is No Such File as: " << filename << endl;
        cout << endl << endl << "-------------" << endl;
        system("pause");
        return 0;
    }


    // Lambda Function to Remove Chars From Head and Tail of Any String
    auto ftrim = [](string &item, string &trim){
        int pos_s = item.find_first_not_of(trim);
        int pos_e = item.find_last_not_of(trim);
        item = item.substr(pos_s, pos_e-pos_s+1);};


    int index_s;                    // Index of the Current Line If It Already Exists in the "Line" Vector
    int index_w;                    // Index of the Current Word If It Already Exists in the "Word" Vector
    string str;                     // String Variable to Store Each Line Read from the Input File
    string trim = ".,:;- \t";       // Characters to Be Removed from Heads and Tails of Each Line
    auto tok = ".,:;- \t";          // Tokens to Be Used in strtok() to Extract Words from Each Line
    vector<Line> line;          	// Vector to Store Unique Lines with their Number of Occurrences
    vector<Line> word;              // Vector to Store Unique Words with their Number of Occurrences
    char *arr, *pch;                // Char Array and Char Pointer to Be Used in strtok() Function

    while(getline(infile, str)){    // While Getting Each Line from the File

        // Extracting Lines:
        ftrim(str, trim);           // Removing Trim Characters (' ', '\t') from Heads and Tails of Each Line

        index_s = distance(line.begin(), find_if(begin(line), end(line), [&str](Line &item) { return item.first == str; }));

        if(index_s == int(line.size()))
            line.push_back(Line(str, 1));
        else
            line.at(index_s).second++;

        /////////////////////////////////////

        // Extracting Words:
        arr = new char[str.length()+1];
        strcpy(arr, str.c_str());
        pch = strtok(arr, tok);

        while( pch != NULL ){

            index_w = distance(word.begin(), find_if(begin(word), end(word), [&pch](Line &item) { return item.first == pch; }));

            if(index_w == int(word.size()))
                word.push_back(Line(pch, 1));
            else
                word.at(index_w).second++;

            pch = strtok(NULL, tok);
        }

        delete[] arr;


    }infile.close();        // Close the Text File


    //////////////////////////////////////////////////////////////////////////////////////////
    // NOTE: Let's Create Two Text Files Which will Store the Line and Word Occurrences
    size_t ind = filename.find_last_of('.');    // The last occurrence of '.' in the filename
    string lines = filename.substr(0, ind) + "_lines" + filename.substr(ind);
    string words = filename.substr(0, ind) + "_words" + filename.substr(ind);

	fstream sFile, wFile;                       // Files to Write Line and Word Occurrences
	sFile.open(lines, ios::out);
	wFile.open(words, ios::out);
    //////////////////////////////////////////////////////////////////////////////////////////


    // Sorting Elements of the "Line" Vector by Strings and by Number of Their Occurrences
    sort(line.begin(), line.end(), [](Line &left, Line &right){return left.first < right.first;});
    sort(line.begin(), line.end(), [](Line &left, Line &right){return left.second < right.second;});

    cout << "List of Line Occurrences:" << endl << endl;
    sFile << "List of Line Occurrences:" << endl << endl;
    for(size_t i=0; i<line.size(); i++){
        cout << "[" << line.at(i).second << "] " << line.at(i).first << endl;
        sFile << "[" << line.at(i).second << "] " << line.at(i).first << endl;
    }cout << endl;
    sFile.close();


    // Sorting Elements of the "Word" Vector by Strings and by Number of Their Occurrences
    sort(word.begin(), word.end(), [](Line &left, Line &right){return left.first < right.first;});
    sort(word.begin(), word.end(), [](Line &left, Line &right){return left.second < right.second;});

    cout << endl << "List of Word Occurrences:" << endl << endl;
    wFile << "List of Word Occurrences:" << endl << endl;
    for(size_t i=0; i<word.size(); i++){
        cout << "[" << word.at(i).second << "] " << word.at(i).first << endl;
        wFile << "[" << word.at(i).second << "] " << word.at(i).first << endl;
    }cout << endl;
    wFile.close();


cout << endl << "Written in: " << lines << endl;
cout << setw(12 + words.length()) << words << endl;

cout << endl << endl << "-------------" << endl;
system("pause");
return 0;
}
