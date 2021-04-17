N, M = map(int, input().split())
bits = []
ANS = 0
string = ''

for i in range(N):
	string = input()

	bits.append(string)

K = int(input())

for i in range(K, -1, -2):
	lst = []
	for j in range(N):
		if i == bits[j].count('0'):
			lst.append(bits[j])

	if len(lst) != 0:
		ANS = max(ANS, max([lst.count(s) for s in lst]))

print(ANS)
