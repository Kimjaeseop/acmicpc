N, M = map(int, input().split())

def func(depth, lst):
	if depth == M-1:
		print(*lst)
		return

	for i in range(1, N+1):
		if i not in lst:
			lst[depth+1] = i
			func(depth+1, lst)
			lst[depth+1] = 0

for i in range(1, N+1):
	arr = [0 for _ in range(1, M+1)]

	arr[0] = i
	func(0, arr)

