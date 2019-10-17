function dataSignal = encode(f,t,data)
    dataSignal = cos(2*pi*f*t + 2*pi*data/4);
end