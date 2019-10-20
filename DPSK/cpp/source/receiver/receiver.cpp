#include "./receiver.h"

int main()
{
    string fileName = "../wav/output.wav";
    double sig[SIGNAL_SIZE];
    clearArr((char*)sig,8*SIGNAL_SIZE);
    getSig(fileName, sig);

    char ps[PS_SIZE];
    clearArr(ps, PS_SIZE);
    getps(sig, ps);

    char datArr[DATA_SIZE];
    clearArr(datArr);
    getData(ps,datArr);
    cout << "The following data were received:\n";
    cout << datArr << endl;

}



void clearArr(char arr[], int size)
{
    for(--size; size >=0; size--)
        arr[size] = 0;
}

void getSig(string fileName, double sig[])
{
    ifstream dataFile(fileName, ios::binary);
    short wav[SIGNAL_SIZE];
    dataFile.seekg(44);

    dataFile.read((char*)wav, sizeof(short)*SIGNAL_SIZE);

    for(int i = 0; i<SIGNAL_SIZE; i++)
        sig[i] = ((double)wav[i])/((double)32767);
}

void getps(double sig[], char ps[])
{
    ps[0] = 0;
    for(int i = 1; i<PS_SIZE; i++)
        ps[i] = decode(&sig[BIT_LEN*i]);
}

char decode(double per[])
{
    int psVal[4] = {0,0,0,0};
    for(int i = 0; i<BIT_LEN; i++)
        for(int j = 0; j<4; j++)
            psVal[i] += abs(per[j]-per[(j+i)%4-BIT_LEN]);

    char min = 0;
    for(int i = 0; i<4; i++)
        if(psVal[i]<psVal[min])
            min = i;
    
    return min;
}

void getData(char ps[], char datArr[])
{
    for(int i = 0; i<PS_SIZE; i++)
        datArr[i/4] += ps[i]<<(2*(i % 4));    
}