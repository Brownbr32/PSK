#include "./transmitter.h"



int main(int argc, char* argv[])
 {
    // gets the data from the followin file
    string fileName = "./txt/data.txt"; 
    char datArr[DATA_SIZE];
    clearArr(datArr);
    getData(datArr, fileName);

    // outputs data to screen.
    cout << datArr << endl;

    // makes array of the phase-shift values
    char psArr[PS_SIZE];
    clearArr(psArr,PS_SIZE);
    getdps(datArr, psArr);

    // makes array of sine values for phase shift.
    double sigArr[SIGNAL_SIZE];
    clearArr((char*)sigArr,8*SIGNAL_SIZE);
    getSig(psArr,sigArr);

    // outputs sine values to .wav file.
    sig2Wav(sigArr);


 }




void clearArr(char arr[], int size)
{
    for(--size; size >=0; size--)
        arr[size] = 0;
}

void getData(char arr[DATA_SIZE], string fileName)
{
    ifstream dataFile(fileName);
    for(int i = 0; i<DATA_SIZE; i++)
        if(!dataFile.get(arr[i]))
            break;
}

void getdps(char data[DATA_SIZE], char ps[PS_SIZE])
{
    int i;
    // gets CPSK
    for(i = 0; i<PS_SIZE; i++)
        ps[i] = (data[i/4]>>(2*i%4))&3;
    
    // gets DPSK
    for(i = 1; i<PS_SIZE; i++)
        ps[i] = (ps[i-1]+ps[i])%4;
}

void getSig(char ps[], double sig[])
{
    double t[SIGNAL_SIZE];
    int i;
    int numReps = NYQUIST*NUM_PERIODS;
    for(i = 0; i < SIGNAL_SIZE; i++)
        t[i] = ((double)i)/((double)(NYQUIST));
    for(i = 0; i<SIGNAL_SIZE; i++)
        sig[i] = cos(2*PI*t[i] + ps[i/(numReps)]*PI/2);
}

void sig2Wav(double sig[])
{
    short wav[SIGNAL_SIZE+25];
    int* ch = (int*)wav;
    char header[44] = {82, 73, 70, 70, -108, 23, 0, 0, 87, 65, 86, 69, 102, 109, 116, 32, 16, 0, 0, 0, 1, 0, 1, 0, 40, 5, 0, 0, 80, 10, 0, 0, 2, 0, 16, 0, 100, 97, 116, 97, 112, 23, 0, 0};
    int headr[11] = {1179011410, 6036, 1163280727, 544501094, 16, 65537, Fs*NYQUIST, 2640, 1048578, 1635017060, SIGNAL_SIZE+50};
    for(int i = 0; i< 11; i++)
    {
        *ch = headr[i];
        ch++;
    }
    for(int i = 22; i < SIGNAL_SIZE+22; i++)
        wav[i] = (short)(((double)32767)*sig[i-22]);
    for(int i = SIGNAL_SIZE; i < SIGNAL_SIZE+3; i++)
        wav[i] = 0;

    ofstream myFile ("./wav/test.wav");
    myFile.seekp(0);
    myFile.write((char*)wav, SIGNAL_SIZE*2+50);
    myFile.close();
}