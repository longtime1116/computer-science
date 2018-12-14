% brew cask install xquartz
% brew cask install aquaterm
% brew uninstall gnuplot
% brew install gnuplot --with-aquaterm

a = pi
disp(a)
disp(sprintf('2 decimals: %0.2f', a))
format long
a
format short
a

A = [ 1 2; 3 4; 5 6]

v = 0:0.1:0.5
v2 = 0:1:5

B = [v;v2]


C = 2 * ones(2,3)
D = zeros(2,4)
E = rand(3,3)

% ガウシアンモデル
w = -6 + sqrt(10) * randn(1,10000)
hist(w)
