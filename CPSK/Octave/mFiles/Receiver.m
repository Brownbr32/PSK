signal = csvread("../csv/signal.csv");
data = csvread("../csv/data.csv");
glob = csvread("../csv/global.csv");
f = glob(1);
nyquistSamp = glob(2);

len = length(signal);
signalPeriod = len/(f*nyquistSamp)-1/(f*nyquistSamp);
t = 0:1/(f*nyquistSamp):signalPeriod;

err = 0;
for i = 1:3:300;

    sample = [signal( i ),signal(i+1),signal(i+2)];
    dat = decodePeriod(sample,nyquistSamp);

    if(data(ceil(i/3))!=dat)
        err = 1;
        out = [data(ceil(i/3)),dat];
        disp([ceil(i/3),out])
    end
end
if(err == 0)
    disp("\nNo errors found")
end
