def longestRun(L):
    count = 1
    max_count = 1
    for i in range(len(L) - 1):
        if L[i] <= L[i+1]:
            count += 1
        else:
            max_count = max(count, max_count)
            count = 1
        max_count = max(count, max_count)
    return max_count




L = [10, 4, 6, 8, 3, 4, 5, 7, 7, 2]
print("[10, 4, 6, 8, 3, 4, 5, 7, 7, 2] must be 5")
print(longestRun(L))

L = [1,2,3,4,5]
print(str(L) + " must be 5")
print(longestRun(L))

L = [1,2,3,3,4,5,5]
print(str(L) + " must be 7")
print(longestRun(L))

L = [5,4,3,2,1]
print(str(L) + " must be 1")
print(longestRun(L))

L = [5,4,3,3,2,1]
print(str(L) + " must be 2")
print(longestRun(L))
