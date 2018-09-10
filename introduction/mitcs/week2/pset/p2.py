balance = 3329 # => 310
balance = 4773 # => 440
#balance = 3926 # => 360
annualInterestRate = 0.2

# 10
balance=90
annualInterestRate = 0.25

def calc_remain(balance, fixed):
    for i in range(12):
        balance = balance - fixed
        balance = balance + balance * annualInterestRate / 12
    return balance

initial_fixed = (balance // 120) * 10
max_fixed = (int(balance * (1 + annualInterestRate)) // 120 + 1) * 10

for i in range((max_fixed - initial_fixed) // 10 + 1):
    fixed = initial_fixed + i * 10
    if calc_remain(balance, fixed) <= 0.0:
        print("Lowest Payment:", fixed)
        break
