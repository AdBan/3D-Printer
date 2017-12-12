clc; clear all;
delete(instrfind);

% Open serial port
s = serial('COM5', 'BaudRate', 57600);
fopen(s);
pause(1);

tic
for t = 0:1:3
    fprintf(s,'x10000 y20000 z1000000 \n');
    xd = fread(s,30)
    
end
toc

fclose(s);