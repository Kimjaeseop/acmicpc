import sys

#input = sys.stdin.readline
sys.stdin = open('input_1.txt', 'r')

N = int(input())

for i in range(N):
	l, r = map(str, input().split('-'))

	l_length = len(l)-1

	l_sum = 0
	r_sum = 0

	for j in l:
		l_sum += ((ord(j)-65)*(26**l_length))
		l_length -= 1

	print('nice' if abs(l_sum-int(r)) <= 100 else 'not nice')
