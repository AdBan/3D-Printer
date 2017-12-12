clc; clear all;
delete(instrfind);

% Open serial port
s = serial('COM3', 'BaudRate', 57600);
fopen(s);
pause(1);

% Send frame
% fprintf(s, 'x6000 y6000 z6000');
% fclose(s);

%% Columns [x y z]
% Lower
p1d = [0 0 0];
p2d = [0 16.5 0];
p3d = [14.29 8.25 0];

% Upper
p1u = [0 0 60];
p2u = [0 16.5 60];
p3u = [14.29 8.25 60];

pc = [7 8.25 30];

r = 21.5;

zc = [0 0 0];

zc(1) = pc(3) + sqrt(r^2 - (p1d(1) - pc(1))^2 - (p1d(2) - pc(2))^2);
zc(2) = pc(3) + sqrt(r^2 - (p2d(1) - pc(1))^2 - (p2d(2) - pc(2))^2);
zc(3) = pc(3) + sqrt(r^2 - (p3d(1) - pc(1))^2 - (p3d(2) - pc(2))^2);

odc1 = line([p1d(1) p1u(1)],[p1d(2) p1u(2)],[p1d(3) p1u(3)]);
odc2 = line([p2d(1) p2u(1)],[p2d(2) p2u(2)],[p2d(3) p2u(3)]);
odc3 = line([p3d(1) p3u(1)],[p3d(2) p3u(2)],[p3d(3) p3u(3)]);
odc4 = line([p1d(1) pc(1)],[p1d(2) pc(2)],[zc(1) pc(3)]);
odc5 = line([p2d(1) pc(1)],[p2d(2) pc(2)],[zc(2) pc(3)]);
odc6 = line([p3d(1) pc(1)],[p3d(2) pc(2)],[zc(3) pc(3)]);
axis equal;
view(24, 8);

hold on;

for t = 0 : 0.5 : 200
    pc = [7 + sin(t),8.25 + cos(t), 1 + t];
    zc(1) = pc(3) + sqrt(r^2 - (p1d(1) - pc(1))^2 - (p1d(2) - pc(2))^2);
    zc(2) = pc(3) + sqrt(r^2 - (p2d(1) - pc(1))^2 - (p2d(2) - pc(2))^2);
    zc(3) = pc(3) + sqrt(r^2 - (p3d(1) - pc(1))^2 - (p3d(2) - pc(2))^2);
    
    if exist('z01', 'var') && exist('z02', 'var') && exist('z03', 'var')
        krok1 = -(zc(1) - z01);
        krok2 = -(zc(2) - z02);
        krok3 = -(zc(3) - z03);
        frame = ['x' num2str(round(krok1*2000)) 'y' num2str(round(krok2*2000)) 'z' num2str(round(krok3*2000)) '\n'];
        fprintf(s, frame);
        pause(2);
    end 
  
    set(odc4, 'XData', [p1d(1) pc(1)],'YData', [p1d(2) pc(2)], 'ZData', [zc(1) pc(3)]);
    set(odc5, 'XData', [p2d(1) pc(1)],'YData', [p2d(2) pc(2)], 'ZData', [zc(2) pc(3)]);
    set(odc6, 'XData', [p3d(1) pc(1)],'YData', [p3d(2) pc(2)], 'ZData', [zc(3) pc(3)]);
    plot3(pc(1), pc(2), pc(3), 'r.', 'MarkerSize', 0.5);
    z01 = zc(1);
    z02 = zc(2);
    z03 = zc(3);
end