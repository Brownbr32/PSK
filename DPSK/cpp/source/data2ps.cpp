#include<iostream>
#include<fstream>
#include<string>
using namespace std;

#define DATA_SIZE 300
class data2ps {
    private:
        char datArr[DATA_SIZE];
        int bitIndex;
    public:
        char getBits(int);
        char nextBits();
        data2ps();
        data2ps(char*);

};

data2ps::data2ps() 
 {
    datArr[0] = 'a';
    for(int i = 0; i<DATA_SIZE; i++)
        datArr[i] =0;
    for(int i = 1; i<DATA_SIZE; i++)
    {
        datArr[i] = datArr[i-1]+1;
    }
    bitIndex = 0;
 }


data2ps::data2ps(char* fileName) 
 {
    ifstream dataFile(fileName);
    
    for(int i = 0; i<DATA_SIZE; i++)
        datArr[i] =0;
    for(int i = 0; i<DATA_SIZE; i++)
    {
        if(!dataFile.get(datArr[i]))
            break;
    }
    bitIndex = 0;
 }

char data2ps::getBits(int offset) 
 {
    if (offset > DATA_SIZE*4) return -1;
    char byte = datArr[offset/4];
    byte = byte>>2*(offset%4);
    return 3&byte;
 }

char data2ps::nextBits() 
 {
    if (bitIndex > DATA_SIZE*4) return -1;
    char byte = datArr[bitIndex/4];
    byte = byte>>2*(bitIndex%4);
    bitIndex++;
    return 3&byte;
 }
