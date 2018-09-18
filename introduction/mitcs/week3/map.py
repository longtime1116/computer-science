for e in map(abs, [-1, 4, -5, 6]):
    print(e)

for e in map(min, [-1, 4, -5, 6], [-2, 5, -4, 7]):
    print(e)



def applyToEach(L, f):
    for i in range(len(L)):
        L[i] = f(L[i])

testList = [1, -4, 8, -9]
applyToEach(testList, abs)
print(testList)

testList = [1, -4, 8, -9]
applyToEach(testList, lambda x: x + 1)
print(testList)

testList = [1, -4, 8, -9]
applyToEach(testList, lambda x: x * x)
print(testList)
