function data = decodePeriod(period, nyquistSamp)
    n = 0:1/nyquistSamp:(1-1/nyquistSamp);
    n *= 2*pi;
    zero = cos(n);
    one  = cos(n+pi/2);
    two  = cos(n+pi);
    three= cos(n-pi/2);
    one = round(sum(abs(one - period)));
    two = round(sum(abs(two - period)));
    three = round(sum(abs(three - period)));
    data = ~one+2*~two+3*~three; % future suggestion:
                    % compare and return index of lowest value
end