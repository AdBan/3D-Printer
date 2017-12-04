clc; clear all;
delete(instrfind);

% Open serial port
s = serial('COM3', 'BaudRate', 57600);
fopen(s);
pause(1);

% Send frame
fprintf(s, 'x6000 y6000 z6000');
fclose(s);


%% Kinematics
armLength = 21.8;