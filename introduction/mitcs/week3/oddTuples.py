def oddTuples(aTup):
    '''
    aTup: a tuple

    returns: tuple, every other element of aTup. 
    '''
    result = ()
    for i in range(len(aTup)):
        if i % 2 == 0:
            result = result + (aTup[i],)

    return result


def oddTuples2(aTup):
    return aTup[::2]
