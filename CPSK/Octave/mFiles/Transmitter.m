data = csvread("../csv/data.csv");
glob = csvread("../csv/global.csv");
f = glob(1);
nyquistSamp = glob(2);

len = length(data);
signalPeriod = len/f-1/(f*nyquistSamp);

v = nyquistSamp+zeros(len,1);

r = [[1:len].',v].';
size(r)

modifiedData = repelems(data,r);

t = 0:1/(f*nyquistSamp):signalPeriod;
n = 0:nyquistSamp*len-1;







unmodifiedSignal = cos(2*pi*f*t);
dataSignal = encode(f,t,modifiedData);
tmp = acos(dataSignal)/(2*pi);
csvwrite('../csv/signal.csv',dataSignal);

audiowrite("./unmodified.wav",unmodifiedSignal,f*nyquistSamp);
audiowrite("./data.wav",dataSignal,f*nyquistSamp);

subplot(2,1,1); stem(n,unmodifiedSignal); title("Unmodified Signal (n)");
subplot(2,1,2); stem(n,dataSignal); title("Data Signal (n)");
print -dpng "../graphs/signalStem.png"

subplot(2,1,1); plot(n,unmodifiedSignal); title("Unmodified Signal (n)");
subplot(2,1,2); plot(n,dataSignal); title("Data Signal (n)");
print -dpng "../graphs/signalPlot.png"

[dataFrequencies, frequencies] = fft(dataSignal);
unmodifiedFrequency = fft(unmodifiedSignal);

subplot(2,1,1); plot(unmodifiedFrequency); title("Unmodified Signal (frequency)");
subplot(2,1,2); plot(dataFrequencies); title("Data Signal (frequency)");
print -dpng "../graphs/frequencySpectrum.png"

