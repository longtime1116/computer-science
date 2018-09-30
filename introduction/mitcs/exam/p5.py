def uniqueValues(aDict):
    '''
    aDict: a dictionary
    '''
    uniqueKeyList = []
    for k, v in aDict.items():
        if list(aDict.values()).count(v) == 1:
            uniqueKeyList.append(k)
    return sorted(uniqueKeyList)



print(uniqueValues({'k1': 1, 'k2': 2, 'k3': 3}))
print(uniqueValues({'k1': 1, 'k2': 1, 'k3': 3}))
print(uniqueValues({0: 3, 1: 2, 2: 3, 3: 1, 4: 0, 6: 0, 7: 4, 8: 2, 9: 7, 10: 0}))
