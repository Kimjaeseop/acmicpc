import sys
#input = sys.stdin.readline

sys.stdin = open('input_1.txt', 'r')

arr = [0 for num in range(26)]

while True:
	try:
		res = []
		string = list(input())
		res.extend(ord(num)-97 for num in string if num.isalpha())
		for i in res:
			arr[i] += 1

	except EOFError:
		break

MAX = max(arr)
[print(chr(i+97), end='') for i, j in enumerate(arr) if j == MAX]
print()
