s = 'azcbobobegghakl'
#s = 'ababc'
#s = 'abcab'

start = 0
end = 0
for i in range(len((s))):
    for j in range(i + 1, len(s)):
        if s[j - 1] > s[j]:
            if end - start < j - i:
                start = i
                end = j
            break
        if j == len(s) - 1 and end - start < j + 1 - i:
            start = i
            end = j + 1

print("Longest substring in alphabetical order is:", s[start:end])
