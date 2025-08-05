def main():
    n = int(input())
    s = input()
    t = input()
    for i in range(n):
        if s[i] == '0' and t[i] == '1':
            print("NO")
            return
        if s[i] == '0' and t[i] == '0':
            continue
        else:
            break
    print("Yes")
    
t = int(input())
for i in range(t):
    main()
        