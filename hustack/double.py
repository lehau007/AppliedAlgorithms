n = int(input())
arr = list(map(int, input().split()))

dict = {}
for num in arr:
    if num not in dict:
        dict[num] = True
        print(0)
    else:
        print(1)