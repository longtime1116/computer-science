def deep_reverse(L):
    """ assumes L is a list of lists whose elements are ints
    Mutates L such that it reverses its elements and also 
    reverses the order of the int elements in every element of L. 
    It does not return anything.
    """
    L2 = list(L)
    list_count = len(L)
    for i in range(list_count):
        L[i] = L2[list_count - i - 1]
        L3 = list(L[i])
        letter_count = len(L[i])
        for j in range(letter_count):
            L[i][j] = L3[letter_count - j - 1]


# For example, if L = [[1, 2], [3, 4], [5, 6, 7]] then deep_reverse(L) mutates L to be [[7, 6, 5], [4, 3], [2, 1]]
L = [[1, 2], [3, 4], [5, 6, 7]]
deep_reverse(L)
print(L)
