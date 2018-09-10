balance = 320000
annualInterestRate = 0.2

#balance = 999999
#annualInterestRate = 0.18

import math

def calc_remain(balance, fixed):
    for i in range(12):
        balance = balance - fixed
        balance = balance + balance * annualInterestRate / 12
    return balance

initial_fixed = math.floor((balance / 12.0))
max_fixed = math.ceil(balance * (1 + annualInterestRate) / 12.0)

def calc_rowest_payment(start, end, balance):
    fixed = round((start + end) / 2, 3)
    remain = calc_remain(balance, fixed)

    if end - start < 0.01:
        return round(fixed, 2)

    if remain < 0.0:
        return calc_rowest_payment(start, fixed, balance)
    else:
        return calc_rowest_payment(fixed, max_fixed, balance)

print("Lowest Payment", calc_rowest_payment(initial_fixed, max_fixed, balance))
