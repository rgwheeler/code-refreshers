#include <stdio.h>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
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
        stringstream ss(line);
        int num;
        vector<int> numbers;
        int index = 0;
        int difference;

        while (ss >> num)
        {
            numbers.push_back(num);
            index ++;
        }

        valid ++;
        if (numbers[0] < numbers[1]) // increasing
        {
            difference = numbers[1] - numbers[0];

            for (int i = 0; i < index -1; i++)
            {
                if (numbers[i] > numbers[i+1])
                {
                    valid --;
                    break;
                }
                else if(numbers[i] == numbers[i+1])
                {
                    valid --;
                    break;
                }
                else if(numbers[i+1] - numbers[i] != difference)
                {
                    valid --;
                    break;
                }
            }
        }
        else if (numbers[0] > numbers[1]) // increasing
        {
            difference = numbers[0] - numbers[1];

            for (int i = 0; i < index -1; i++)
            {
                if (numbers[i] < numbers[i+1])
                {
                    valid --;
                    break;
                }
                else if(numbers[i] == numbers[i+1])
                {
                    valid --;
                    break;
                }
                else if(numbers[i] - numbers[i+1] != difference)
                {
                    valid --;
                    break;
                }
            }
        }


        cout << valid << "  ";
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