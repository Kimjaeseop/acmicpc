N = int(input())
ans = 0

for i in range(N):
	s = input()
	lst = []

	if len(s) == 1:
		ans += 1
	else:
		groupWord = 1
		for j in range(len(s)):
			if j+1 < len(s) and s[j] == s[j+1]:
				continue

			if s[j] in lst:
				groupWord = 0
				break

			lst.append(s[j])

		if groupWord == 1:
			ans += 1

print(ans)
