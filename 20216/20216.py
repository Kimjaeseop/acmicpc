import sys

sys.stdin = open('input_2.txt', 'r')
print()

while True:
	string = input()

	if string == 'I quacked the code!':
		sys.exit()

	if string[-1] == '.':
		print('*Nod*')
	elif string[-1] == '?':
		print('Quack!')

	sys.stdout.flush()

