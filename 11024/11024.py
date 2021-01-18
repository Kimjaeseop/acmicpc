import sys

sys.stdin = open('input.txt', 'r')

testcase = int(input())

for i in range(testcase):
	N = [int(n) for n in input().split()]
	print(sum(N))

