import sys

sys.stdin = open('input.txt', 'r')

for i in range(3):
	cnt = 0
	'''
	굳이 이렇게 하지 않더라도 list slicing으로 처리가능

	example )
	h1, m1 = int(string[0:2]), int(string[3:5])
	'''

#l, r = input().split()
	string = input().split()

	h = [0 for j in range(2)]
	m = [0 for j in range(2)]
	s = [0 for j in range(2)]

	for j in range(2):
		h[j], m[j], s[j] = map(int, string[j].split(':'))

	while True:
		if s[0] > 59:
			m[0] += 1
			s[0] = 0

		if m[0] > 59:
			h[0] += 1
			m[0] = 0

		if h[0] > 23:
			h[0] = 0

# ans += int((h1 * 10000 + m1 * 100 + s1) % 3 == 3)
		num = (h[0] * 10000) + (m[0] * 100) + s[0]

		if num % 3 == 0:
			cnt += 1

		if h[0] == h[1] and m[0] == m[1] and s[0] == s[1]:
			break

		s[0]+=1

	print(cnt)


