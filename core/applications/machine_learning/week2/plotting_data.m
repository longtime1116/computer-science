t = [0:0.01:0.98]
y1 = sin(2 * pi * 4 * t)
y2 = cos(2 * pi * 4 * t)

plot(t, y1)
hold on;
plot(t, y2, 'r')
xlabel('time')
ylabel('value')
legend('sin', 'cos')
title('my plot')
print -dpng 'myPlot.png'

close

figure(1): plot(t, y1)
figure(2): plot(t, y2)
subplot(1,2,1) % divide plot a 1x2 grid, access first element
plot(t, y1)
subplot(1,2,2) % divide plot a 1x2 grid, access second element
plot(t, y2)
axis([0.5 1 -1 1]) % xaxis: 0.5〜1, yaxis: -1〜1


clf; % clear figure

A = magic(50)
imagesc(A)
imagesc(A), colorbar, colormap gray;

a = 1, b = 2, c = 3 % comma chaining command
