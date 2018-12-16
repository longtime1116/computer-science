v = zeros(10, 1)
for i=1:size(v, 1),
  v(i) = 2^i;
end;

indices = 1:10
for i=indices,
  disp(i);
end;

i = 1;
while i <= 5,
  v(i) = 100;
  i = i+1;
end
v

i = 1;
while true,
  v(i) = 999;
  i = i + 1;
  if i == 6,
    break;
  end
end
v

v(1) = 2;
if v(1) == 1,
  disp('The value is one.')
elseif v(1) == 2,
  disp('The value is two.')
else,
  disp('The value is not one or two')
end;

addpath('./')
squareThisNumber(5)
[a, b] = squareAndCubeThisNumber(5)


X = [1 1; 1 2; 1 3] % x values of my three training examples
y = [1; 2; 3]
theta = [0;1]
costFunctionJ(X, y, theta)
