L1 = [0, 1, 2]
L2 = [3, 4, 5]
L3 = L1 + L2
print("L1: ", L1)
print("L2: ", L2)
print("L3: ", L3)
L1.extend(L2)
print("L1 is extended")
print("L1: ", L1)

print("L1.append(1)")
L1.append(1)
print("L1: ", L1)

print("L1[2] is deleted")
del(L1[2])
print("L1: ", L1)

print("L1.remove(1)")
L1.remove(1)
print("L1: ", L1)

print("==================")

L = [9, 6, 0, 3]
print("L: ", L)

print("sorted(L)")
print(sorted(L))
print("L: ", L)


print("L.sort()")
L.sort()
print("L: ", L)

print("L.reverse()")
L.reverse()
print("L: ", L)

print("L.append(10)")
L.append(10)
print("L: ", L)

print("L.pop()")
L.pop()
print("L: ", L)

print("L.pop(0)")
L.pop(0)
print("L: ", L)

print("==================")

L1 = [1, 2, 3, 4]
print("L1: ", L1)
L2 = [1, 2, 5, 6]
print("L2: ", L2)

def remove_dups(L1, L2):
    for e in L1:
        if e in L2:
            L1.remove(e)
# mutable である配列を操作してしまっているので、結果が変になる
print("remove_dups(L1, L2)")
remove_dups(L1, L2)
print("L1:", L1) #=> [2, 3, 4]

print("〜reset〜")
L1 = [1, 2, 3, 4]
print("L1: ", L1)
L2 = [1, 2, 5, 6]
print("L2: ", L2)

def remove_dups_new(L1, L2):
    for e in L1[:]:
        if e in L2:
            L1.remove(e)
print("remove_dups_new(L1, L2)")
remove_dups_new(L1, L2)
print("L1:", L1) #=> [2, 3, 4]
