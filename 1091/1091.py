N = int(input())

P = list(map(int, input().split()))
S = list(map(int, input().split()))

lst = [i for i in range(N)]
log = []

count = 0

def ansCheck(P, lst):
	for i in range(N):
		if P[lst[i]] != i%3:
			return False

	return True

while count <= 200000:
	if ansCheck(P, lst) == True:
		break

	temp_lst = lst[:] # temp_lst = lst로 copy하면 lst 변경 시, temp_lst도 함께 변경된다

	for i in range(N):
		lst[S[i]] = temp_lst[i]

	count+=1

print(count if count <= 200000 else -1)

