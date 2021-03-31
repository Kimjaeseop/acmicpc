N, M = map(int, input().split())

def func(depth, lst):
	if depth == M-1:
		print(*lst)
		return

	if N-max(lst) < M-(depth+1): # 유망하지 않은 노드 제거
		return

	for i in range(max(lst)+1, N+1): # 오름차순이기 때문에 가장 큰 값 다음 값부터 시작
		if i not in lst:
			lst[depth+1] = i 
			func(depth+1, lst)
			lst[depth+1] = 0 

for i in range(1, N+1):
	arr = [0 for _ in range(1, M+1)]

	arr[0] = i 
	func(0, arr)
