N = int(input())
lst = [i for i in range(10)]
top = 0

while lst[-1] < 9876543210:
	s = str(lst[top])

	for i in range(int(s[0])+1, 10):
		lst.append(int(str(i) + str(s)))

	top += 1

lst = sorted(lst)

print(lst[N] if len(lst) > N else -1)
