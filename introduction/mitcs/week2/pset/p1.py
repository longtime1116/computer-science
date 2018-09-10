#balance = 42
#annualInterestRate = 0.2
#monthlyPaymentRate = 0.04
# => 31.38

balance = 484
annualInterestRate = 0.2
monthlyPaymentRate = 0.04
# => 361.61

b = balance
for i in range(12):
    ub = b - b * monthlyPaymentRate
    b = ub + annualInterestRate * ub / 12.0
    #print(i + 1, ":", b)

print("Remaining balance:", round(b, 2))
