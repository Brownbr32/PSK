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
%dataSignal = cos(2*pi*f*t + 2*pi*modifiedData/4);
dataSignal = encode(f,t,modifiedData);
tmp = acos(dataSignal)/(2*pi);
disp(dataSignal)
csvwrite('./csv/signal.csv',dataSignal);

subplot(2,1,1); stem(n,unmodifiedSignal); title("Unmodified Signal (n)");
subplot(2,1,2); stem(n,dataSignal); title("Data Signal (n)");
print -dpng "./graphs/signal.png"

