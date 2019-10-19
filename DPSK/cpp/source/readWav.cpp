#include<fstream>
#include<iostream>
#include<stdio.h>

#define DL 6050

using namespace std;

int main()
{
    char file[DL];
    ifstream wavFile("/mnt/c/Users/brown/Documents/CE/sw/PSK/CPSK/Octave/mFiles/unmodified.wav");
    for(int i = 0; i<DL; i++)
        file[i] = 0;
    for(int i = 0; i<DL; i++)
        if(!wavFile.get(file[i]))
            break;
    int charcast = 1;
    for(int i = 0; i<44; i+=4)
    {
        /*
        if (charcast = 1)
            cout << (int)file[i] << " ";
        else*/
            cout /*<< i << ":" */<< *(int*)&file[i] << ", ";
        if((file[i] == 0)&(file[i+1] == -64)&(file[i+2] == -1)&(file[i+3] == 127))
            charcast = 0;
    }
    cout << endl;
}