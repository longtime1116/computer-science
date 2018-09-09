nameHandle = open("list.txt", "w")
for i in range(2):
    name = input("Enter name: ")
    nameHandle.write(name + "\n")
nameHandle.close
print("list.txt is created")

print("===== list.txt =====")
nameHandle = open("list.txt", "r")
for line in nameHandle:
    print(line)
nameHandle.close
