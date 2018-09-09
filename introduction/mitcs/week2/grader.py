import math

def area(n, s):
    return 0.25 * n * s * s / math.tan(math.pi / n)

def square_perimeter(n, s):
    return n * s * n * s

def polysum(n, s):
    '''
    input:
      n: number of sides for a regular polygon
      s: the length of each side
    output:
      polysum: the sum of area and square of the perimeter of the regular polygon
    '''
    return round(area(n, s) + square_perimeter(n, s), 4)


print("Test:", polysum(85, 71))
print("area:", area(85, 71))
print("areabunshi:", 0.25 * 85 * 71 * 71)
print("areabunbo:", math.tan(math.pi / 85))
print("peri:", square_perimeter(85, 71))
print("correct: ", 39318214.1452)
