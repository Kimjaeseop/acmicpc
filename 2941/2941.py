s = input()

lst = {'c=', 'c-', 'dz=', 'd-', 'lj', 'nj', 's=', 'z='}
idx = 0
ans = 0

while idx < len(s):
	if s[idx:idx+2] in lst:
		idx += 1
	elif s[idx:idx+3] in lst:
		idx += 2

	ans += 1
	idx += 1

print(ans)
		
