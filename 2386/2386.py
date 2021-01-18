import sys

sys.stdin = open('input.txt', 'r')

while True:
	string = input()

	if string[0] == '#':
		break
	
	print(string[0], string.lower().count(string[0])-1)
