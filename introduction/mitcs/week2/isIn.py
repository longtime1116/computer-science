def isIn(char, aStr):
    '''
    char: a single character
    aStr: an alphabetized string

    returns: True if char is in aStr; False otherwise
    '''

    middle = len(aStr) // 2

    if len(aStr) == 0:
        return False

    if len(aStr) == 1:
        return char == aStr[0]

    if char == aStr[middle]:
        return True
    elif char < aStr[middle]:
        return isIn(char, aStr[0:middle])
    else:
        return isIn(char, aStr[middle:])

