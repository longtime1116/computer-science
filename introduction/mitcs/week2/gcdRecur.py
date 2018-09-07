def gcdRecur(a, b):
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

