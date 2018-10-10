def genPrimes():
    primes = []
    num = 1
    while True:
        num += 1
        isPrime = True
        for prime in primes:
            if num % prime == 0:
                isPrime = False
                break
        if isPrime:
            primes.append(num)
            yield num

gen = genPrimes()
print(gen.__next__())
print(gen.__next__())
print(gen.__next__())
print(gen.__next__())
print(gen.__next__())
print(gen.__next__())
print(next(gen))
print(next(gen))
print(next(gen))
print(next(gen))
print(next(gen))
