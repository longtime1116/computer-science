# 567 = 441 * 1 + 126
# 441 = 126 * 3 + 63
# 126 = 63 * 2
# therefore, 567 = (((63 * 2) * 3 + 63) + 63 * 2)
# so gcd(567, 441) == 63
def gcdRecur(a, b):
    '''
    a, b: positive integers

    returns: a positive integer, the greatest common divisor of a & b.
    '''
    if (b == 0):
        return a
    else:
        return gcdRecur(b, a % b)


def gcdRecur2(a, b):
    '''
    a, b: positive integers

    returns: a positive integer, the greatest common divisor of a & b.
    '''

    divisor = 1
    for i in range(min(a, b)):
        num = i + 1
        if ( num != 1 and a % num == 0 and b % num == 0 ):
            divisor = num
            break

    if divisor == 1:
        return 1
    else:
        return divisor * gcdRecur(a // divisor, b // divisor)


