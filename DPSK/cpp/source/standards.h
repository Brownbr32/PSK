#include<iostream>
#include<fstream>
#include<stdio.h>
#include<string>
#include<math.h>

#define DATA_SIZE 256
#define PS_SIZE 4*DATA_SIZE
#define NYQUIST 4
#define NUM_PERIODS 1
#define BIT_LEN NYQUIST*NUM_PERIODS
#define SIGNAL_SIZE PS_SIZE*BIT_LEN
#define Fs 440
#define PI 3.14159265358979

using namespace std;