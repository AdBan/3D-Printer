function s = SerialOpen()
    %% Clear previous mfile
    clc; clear all;
    delete(instrfind);

    %% Open serial port
    s = serial('COM3', 'BaudRate', 57600);
    fopen(s);
    pause(1);
end