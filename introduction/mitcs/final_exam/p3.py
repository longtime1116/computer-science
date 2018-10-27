def is_triangular(k):
    """
    k, a positive integer
    returns True if k is triangular and False if not
    """
    count = 1
    while True:
        k -= count
        if k == 0:
            return True
        elif k < 0:
            return False
        count += 1

print("0 must be False")
print(is_triangular(0))

print("1 must be True")
print(is_triangular(1))

print("3 must be True")
print(is_triangular(3))

print("6 must be True")
print(is_triangular(6))

print("10 must be True")
print(is_triangular(10))

print("55 must be True")
print(is_triangular(55))

print("56 must be False")
print(is_triangular(56))
