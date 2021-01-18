import sys

#sys.stdin = open('input.txt', 'r')

num1, sign, num2 = int(input()), input(), int(input())

if sign == '+':
	print(num1 + num2)
else:
	print(num1 * num2)
