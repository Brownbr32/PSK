#include<fstream>
#include<iostream>
#include<stdio.h>

#define DL 9650

using namespace std;

int main()
{
    char file[DL];
    //ifstream wavFile("/mnt/c/Users/brown/Documents/CE/sw/PSK/CPSK/Octave/mFiles/unmodified.wav");
    ifstream wavFile("/mnt/c/Users/brown/Documents/CE/sw/PSK/DPSK/cpp/wav/output.wav");
    for(int i = 0; i<DL; i++)
        file[i] = 0;
    for(int i = 0; i<DL; i++)
        if(!wavFile.get(file[i]))
            break;
    int charcast = 1;
    for(int i = 0; i<DL; i+=2)
            cout /*<< i << ":" */<< *(short*)&file[i] << ", ";
    cout << endl;
}