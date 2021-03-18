N = int(input())
s = ''

for i in range(1, N + 1):
	s += str(i)

print(s.find(str(N)) + 1)
