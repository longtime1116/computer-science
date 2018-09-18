animals = { 'a': ['aardvark'], 'b': ['baboon'], 'c': ['coati']}

animals['d'] = ['donkey']
animals['d'].append('dog')
animals['d'].append('dingo')


#def how_many(aDict):
#    count = 0
#    for e in aDict:
#        count += len(aDict[e])
#    print(count)
#
#

def how_many(aDict):
    '''
    aDict: A dictionary, where all the values are lists.

    returns: int, how many values are in the dictionary.
    '''
    count = 0
    for key in aDict.keys():
        count += len(aDict[key])
    return count

print(how_many({'u': [10, 15, 5, 2, 6], 'B': [15]}))
