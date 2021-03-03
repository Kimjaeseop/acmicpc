import sys
#input = sys.stdin.readline

sys.stdin = open('input_1.txt', 'r')

N = int(input())
arr = list(map(int, input().split()))
print(N)
print(arr)
