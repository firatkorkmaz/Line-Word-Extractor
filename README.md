# Line & Word Extractor
A program to extract unique lines and words from a text file with their repetition counts.

## General Information
This is a C++ program that extracts unique lines and words from an input text file, lists them separately with their repetition counts and saves them in 2 different new text files. There are 5 (.cpp) files in this project, the first 4 files are small preparation programs before the main program which is the 5th file:
1. **1_CharList_Remover.cpp**: Removes a list of characters from a string.
2. **2_String_Trimmer.cpp**: Trims a list of characters from a string by using lambda functions.
3. **3_String_Splitter.cpp**: Splits a string by using 2 different ways: Using strtok() function and using vectors.
4. **4_File_Operations.cpp**: Writes the alphabet letters to a text file by using 2 different ways: Using FILE pointer and using fstream.
5. **5_Line_Word_Extractor.cpp**: The main program: *Line & Word Extractor*
7. **data.txt**: An example input text file for the main program.

## Setup & Run
Compile the *5_Line_Word_Extractor.cpp* file with a C++ compiler and run the executable file. Using a C++ Standard flag (-std=c++xx) is not necessary.
```
g++ 5_Line_Word_Extractor.cpp
```
