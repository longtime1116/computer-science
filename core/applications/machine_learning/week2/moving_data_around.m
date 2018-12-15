A = [1 2; 3 4; 5 6]

sz = size(A)
size(A, 1)
size(A, 2)

B = rand(sz)


v = [1 2 3 4]
length(v)
v2 = [1; 2; 3; 4]
length(v2)


pwd
ls

load featuresX.dat
who % variables
whos % variables in detail

featuresX

%clear featuresX

v = featuresX(2:4) % 2〜4行目


save hello.mat v;

clear

load hello.mat
v

save hello.txt v -ascii

A = [[1; 2] [3; 4]] % [1 3; 2 4]

A = [1 2; 3 4; 5 6]

A(2) % 3
A(2, :) % 3 4
A(:, 2) % [2;4;6]
A([1 3], :) % [1 2; 5 6]

A(:, 2) = [10; 11; 12]
A = [A, [100; 101; 102]]

A(:) % A は3 * 3 だが [1; 3; 5; 10; 11; 12; 100; 101; 102]
