import sys

N = int(input())
M = int(input())

arr = [0 for _ in range(16384)]
arr[0] = arr[1] = 1

for i in range(2, 10001):
	j=2

	while i*j < 10001:
		arr[i*j] = 1
		j+=1

arr = arr[N:M+1]

if 0 not in arr:
	print(-1)
	sys.exit()

ans = 0
for idx, num in enumerate(arr):
	if num == False:
		ans += (idx + N)

print(ans)
print(arr.index(0) + N)


