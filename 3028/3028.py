import sys

sys.stdin = open('input_1.txt', 'r')

ans = 1

string = list(input())

for i in string:
	if i == 'A':
		if ans == 1:
			ans += 1
		elif ans == 2:
			ans -= 1
	elif i == 'B':
		if ans == 2:
			ans += 1
		elif ans == 3:
			ans -= 1
	elif i == 'C':
		if ans == 1:
			ans += 2
		elif ans == 3:
			ans -= 2

print(ans)
