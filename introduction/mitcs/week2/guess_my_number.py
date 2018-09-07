print("Please think of a number between 0 and 100!")

guess = 50
high = 100
low = 0

while True:
    print("Is your secret number %d?" % (guess))
    result = input("Enter 'h' to indicate the guess is too high. Enter 'l' to indicate the guess is too low. Enter 'c' to indicate I guessed correctly. ")
    if len(result) != 1 or result not in "hlc":
        print("Sorry, I did not understand your input.")
        continue
    else:
        if result == "h":
            high = guess
        elif result == "l":
            low = guess
        else:
            print("Game over. Your secret number was:", guess)
            break;
        guess = (low + high) // 2

