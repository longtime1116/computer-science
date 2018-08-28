many steps
O(n^2) : bubble
O(nlogn)
O(n) : linear search
O(logn) : binary search


low steps はオメガで表す(ベストケース)
Ω(n) : bubble
Ω(1) : linear case(初手で決まる)

upper と lower が同じアルゴリズムを、thetaで表す(θ)

log base 2 of n


merge sort

logn で、分割して処理していく
n で、merge 処理をする
T(n) = T(n/2) + T(n/2) + O(n)
なので、nlogn
