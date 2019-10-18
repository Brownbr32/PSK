#include<iostream>
#include<fstream>
#include<stdio.h>
#include<string>

#include "./data2ps.cpp"
#include "./ps2data.cpp"
using namespace std;

int main(int argc, char* argv[])
 {
    string fileName = "./txt/data.txt"; 
    /*if(argc == 2)   data2ps signal(argv[1]);
    else*/ data2ps signal(fileName);
    ps2data data;
    char tmp,t;
    data.printData();
    for(int i = 0; i< 300; i+=4)
    {
        tmp = 0;
        for(int j = 0; j<4; j++)
        {
            t = signal.nextBits();
            data.saveBits(t);
        }
    }
    data.printData();
 }
