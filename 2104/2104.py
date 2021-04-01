N = int(input())
lst = list(map(int, input().split()))

MAX = 0

for i in range(N):
	for j in range(1, N-i+1):
		MAX = max(sum(lst[i:i+j])*min(lst[i:i+j]), MAX)

print(MAX)


