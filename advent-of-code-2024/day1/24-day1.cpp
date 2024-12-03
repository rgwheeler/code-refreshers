#include <iostream>
#include <fstream>
#include <stdio.h>
using namespace std;


void heapify(int arr[], int n, int i);
void heapSort(int arr[], int n);


int main() {
    cout << "Hello World!" << endl;

    ifstream infile("input.txt");

    if (!infile)
    {
        cout << "File could not be opened." << endl;

    }

    int inp1[1000];
    int inp2[1000];
    int n = 1000;
    int sum = 0;

    for (int i = 0; i < 1000; i++)
    {
        infile >> inp1[i] >> inp2[i];
    }

    for(int i=n/2 -1;i>=0;i--){
       heapify(inp1,n,i);
    }
    heapSort(inp1, n);

    for(int i=n/2 -1;i>=0;i--){
       heapify(inp2,n,i);
    }
    heapSort(inp2, n);


    for (int i = 0; i < 1000; i++)
    {
        if (inp1[i] > inp2[i])
        {
            sum += (inp1[i] - inp2[i]);
        }
        else if (inp1[i] < inp2[i])
        {
            sum += (inp2[i] - inp1[i]);
        }
        else if (inp1[i] = inp2[i])
            sum += 0;
    }

    cout << sum << endl;

    return 0;
}



void heapify(int arr[], int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest])
        largest = l;

    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}



void heapSort(int arr[], int n)
{
    for (int i = n/2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i >= 0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }

}


