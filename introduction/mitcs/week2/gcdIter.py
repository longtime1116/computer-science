def gcdIter(a, b):
    '''
    a, b: positive integers

    returns: a positive integer, the greatest common divisor of a & b.
    '''

    gcd = 1
    for i in range(min(a, b)):
        divisor = i + 1
        if (a % divisor == 0 and b % divisor == 0):
            gcd = divisor
    return gcd
