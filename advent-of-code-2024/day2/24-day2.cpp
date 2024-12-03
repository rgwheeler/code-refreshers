#include <stdio.h>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main() {
    fstream infile("input.txt");
    if (!infile)
    {
        cout << "Could not open file\n\n";
        return 0;
    }


    int valid;
    string line;


    while (getline(infile, line))
    {
        istringstream linestring(line);
        int num;
        int index = 0;

        while (linestring >> num)
        {
            index =+ 1;
        }
        int arr[index];
        for (int i = 0; i < index; i++)
        {

        }

        cout << index << "  ";
    }

    return 0;
}


/*

logic

int index
int num

while reading from line
    index + 1

*/