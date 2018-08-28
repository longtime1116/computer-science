import math
import numpy as np

x = int(input("Enter number x: "))
y = int(input("Enter number y: "))

print("x ** y = ", x ** y)
#print("x ** y = " +  str(x ** y))  # the same as above
print("log(x) = ", math.log2(x))
print("log(x) = ", np.log2(x))


a = np.asarray([0, 1, 2, 4, 8, 16])
print("array: ", a)
print("log array: ", np.log2(a))
