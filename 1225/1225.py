import sys
input = sys.stdin.readline

#sys.stdin = open('input.txt', 'r')

l, r = map(str, input().split())
num1 = [int(n) for n in l]
num2 = [int(n) for n in r]

ans = 0
for i in num2:
	ans += sum(num1 * i)

print(ans)

