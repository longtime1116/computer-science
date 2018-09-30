def sumDigits(N):
    '''
    N: a non-negative integer
    '''
    first = N % 10
    rest = N // 10

    if rest == 0:
        return first
    return first + sumDigits(rest)


print(sumDigits(0))
print(sumDigits(1002))
print(sumDigits(1248))
print(sumDigits(1248000))
