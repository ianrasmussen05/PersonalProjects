# Random Student Generator

The purpose of this C++ program is to select students at random. It takes a `.csv` file as input with the names, email, year, and scroll number of the student. It can be by 1) random students, doesn't matter what year, or it can be by 2) randomly by year, or you can 3) print the total students within the imported file. In order for this to work correctly, the user must use a basic C++ compiler, I did my testing on Linux.

## Source Files
* Student.h & Student.cpp
* CSV_Reader.h & CSV_Reader.cpp
* Randomize.h & Randomize.cpp
* main.cpp
* Makefile
* StudentList.csv

## How to Compile
Type in to the command line: 
* `make`

## How to Execute
A new file will be created in the current directory called `generate` and we will use this to run the program. So, type into the command line:
* `./generate StudentList.csv`
Where the `.csv` file is the file inputted