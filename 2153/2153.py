s = ''
cnt = 0
tmp = 0
arr = [0] * 521

s = input().lower()

for c in s:
	cnt += (ord(c) - ord('a') + 1)

arr[1] = 0
for i in range(2, 261):
	for j in range(2, 261):
		tmp = i * j

		if tmp > 520:
			break

		arr[tmp] += 1

if arr[cnt] == 0:
	print("It is a prime word.")
else:
	print("It is not a prime word.")
