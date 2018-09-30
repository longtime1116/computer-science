def evalQuadratic(a, b, c, x):
   '''
   a, b, c: numerical values for the coefficients of a quadratic equation
   x: numerical value at which to evaluate the quadratic.
   '''
   return a*x*x + b*x + c

def twoQuadratics(a1, b1, c1, x1, a2, b2, c2, x2):
    '''
    a1, b1, c1: one set of coefficients of a quadratic equation
    a2, b2, c2: another set of coefficients of a quadratic equation
    x1, x2: values at which to evaluate the quadratics
    '''
    print(evalQuadratic(a1, b1, c1, x1) + evalQuadratic(a2, b2, c2, x2))


print(evalQuadratic(1,2,3,4))
print(evalQuadratic(5,6,7,8))
print(twoQuadratics(1,2,3,4,5,6,7,8))
print(twoQuadratics(2.3, 1.26, 6.93, 5.33,
                    -6.47, -8.66, -9.87, -6.07))
