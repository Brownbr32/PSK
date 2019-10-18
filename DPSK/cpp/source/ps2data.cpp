#include<iostream>
#include<fstream>
#include<string>
using namespace std;

#define DATA_SIZE 300
class ps2data {
    private:
        char datArr[DATA_SIZE];
        int bitIndex;
    public:
        ps2data();
        ps2data(char*);
        int saveBits(char);
        void printData();

};

ps2data::ps2data() 
 {
    bitIndex = 0;
    for(int i = 0; i<DATA_SIZE; i++)
        datArr[i] =0;
 }


ps2data::ps2data(char* fileName) 
 {
    bitIndex = 0;
    for(int i = 0; i<DATA_SIZE; i++)
        datArr[i] =0;
 }

void ps2data::printData()
 {
    cout << datArr << endl;
 }

int ps2data::saveBits(char bits) 
 {
    if (bitIndex > DATA_SIZE*4)
    { 
        cout << "Error\n";
        return -1;
    }
    datArr[bitIndex/4] += bits<<(2*(bitIndex%4));
    bitIndex++;
    return 0;
 }