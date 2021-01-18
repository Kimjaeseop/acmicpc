import sys

sys.stdin = open('input.txt', 'r')

ans = 0

for i in range(8):
	chess = input()
	for j in range(8):
		ans += 1 if (i%2==0 and j%2==0 and chess[j]=='F') or (i%2==1 and j%2==1 and chess[j]=='F') else 0

print(ans)

	
