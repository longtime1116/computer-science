try:
    num = int(input("input number"))
except:
    print("error")
else:
    print(num)
    try:
        1/0
    except ZeroDivisionError:
        print("0 division error")
    else:
        print("no error")
    finally:
        print("end")
finally:
    print("end")
