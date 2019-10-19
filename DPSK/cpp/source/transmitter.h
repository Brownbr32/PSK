#include<iostream>
#include<fstream>
#include<stdio.h>
#include<string>
#include<math.h>

#define DATA_SIZE 300
#define PS_SIZE 4*DATA_SIZE
#define NYQUIST 50
#define NUM_PERIODS 1
#define SIGNAL_SIZE NYQUIST*PS_SIZE*NUM_PERIODS
#define Fs 440
#define PI 3.14159265358979

using namespace std;
void clearArr(char arr[], int size = DATA_SIZE);
void getData(char[], string);
void getdps(char[], char[]);
void getSig(char[], double[]);
void sig2Wav(double sig[]);