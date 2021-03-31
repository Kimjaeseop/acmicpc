N, M = map(int, input().split())

def func(depth, lst):
    if depth == M-1:
        print(*lst)
        return

    for i in range(1, N+1):
        if i not in lst:
            lst[depth+1] = i # 다음 depth 노드에 값 대입
            func(depth+1, lst)
            lst[depth+1] = 0 # 이미 자식노드에 방문하고 부모노드로 다시 올라왔기 때문에 노드에 값 제거

for i in range(1, N+1):
    arr = [0 for _ in range(1, M+1)]

    arr[0] = i 
    func(0, arr)
