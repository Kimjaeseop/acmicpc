import sys
import math
#input = sys.stdin.readline

def getCombination(a, b):
	return math.factorial(a) / math.factorial(a-b) * math.factorial(b)

sys.stdin = open('input_1.txt', 'r')

n = int(input())
kind = int(input())

print(getCombination(2, 1))


