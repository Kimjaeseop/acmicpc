# 못 품
n, m = map(int, input().split())

'''
제곱근 값 구하는 방법

n ** (1/2)

당연한건데 이걸 까먹다니..
'''

num = []
num.append(list(input()))
num.append(list(input()))
ans = 0

for i in range(n):
	for j in range(m):
		for p in range(-n, n):
			for q in range(-m, m):


print(ans)
