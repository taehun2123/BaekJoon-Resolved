input()
a = list(map(int, input().split()))
b = list(map(int, input().split()))
ans = 0

box = a.pop(0)
book = b.pop(0)

try:
    while True:
        if box < book:
            ans += box
            box = a.pop(0)
        else:
            box = box - book
            book = b.pop(0)
except:
    ans += box
    pass
ans += sum(a)
print(ans)