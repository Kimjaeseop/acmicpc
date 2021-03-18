s = ''
cnt = 0

while True:
	s = input()

	if s == '#':
		break

	s = s.lower()
	cnt = 0

	for c in s:
		if c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u' :
			cnt+=1
	
	print(cnt)
	
