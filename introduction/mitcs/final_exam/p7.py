class myDict(object):
    """ Implements a dictionary without using a dictionary """
    def __init__(self):
        """ initialization of your representation """
        self.arykey = []
        self.aryvalue = []

    def assign(self, k, v):
        """ k (the key) and v (the value), immutable objects  """
        i = self.__getIndex(k)
        if i is not None:
            self.delete(k)
        self.arykey.append(k)
        self.aryvalue.append(v)


    def getval(self, k):
        """ k, immutable object  """
        i = self.__getIndex(k)
        if i is None:
            raise KeyError(k)
        return self.aryvalue[i]

    def delete(self, k):
        """ k, immutable object """
        i = self.__getIndex(k)
        if i is None:
            raise KeyError(k)
        del self.arykey[i]
        del self.aryvalue[i]
        return

    def __getIndex(self, k):
        for i in range(len(self.arykey)):
            if self.arykey[i] == k:
                return i
        return None

md = myDict()
md.assign(1,2)
print(md.getval(1))
md.delete(1)
