A = [1 2; 3 4; 5 6]
B = [1 1; 2 2]

A * B

A = [1 2; 1 2; 1 2]
B = [1 1; 2 2; 3 3]

A .* B

B.^2


v = [1;2;3]

1 ./v

1./A


log(v)


exp(1)
exp(v)


abs([-1;2;-3])

-v

v + ones(length(v), 1)

% これで3分まで

A = [1 2;3 4;5 6]
v = [1 15 2 0.5]
sum(A, 1)

A' % A transpose
A''


val = max(A)
val = max(v)

[val, index] =  max(v)
[val, index] =  max(A)


v < 3 % 3 より小さい部分のみ 1 になる！

find(v < 3) % ↑の index が返る版

A = magic(3)

sum(A, 1) % 1 を指定すると、column のものを全て足す
sum(A, 2) % 2 を指定すると、row のものを全て足す


A = magic(9)

A .* eye(9)

sum(A.*eye(9))
sum(sum(A.*eye(9)))

flipud(eye(9))

A = magic(3)
tmp = pinv(A)
tmp * A
