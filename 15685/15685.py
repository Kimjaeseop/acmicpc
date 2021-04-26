N = int(input())

def arrayRotate(lst, arr): # 배열 회전
	size = len(lst)
	std_y = lst[-1][0] # 기준점 (끝점) 저장
	std_x = lst[-1][1]

	for i in range(size-1, -1, -1): 
		y, x = lst[i][0]-std_y, lst[i][1]-std_x # 회전 기준점을 원점으로 이동
		
		lst.append([x+std_y, -y+std_x]) # 회전하고 다시 기준점으로 이동
		arr[x+std_y][-y+std_x] = True

def squareFind(arr, firstY, firstX): # 정사각형 찾는 함수
	if arr[firstY][firstX] == True and arr[firstY][firstX+1] == True and arr[firstY+1][firstX] == True and arr[firstY+1][firstX+1]:
		return True
	
	return False

arr = [[False] * 201 for _ in range(201)]

for _ in range(N):
	x, y, d, g = map(int, input().split())
	lst = []

	arr[y][x] = True
	lst.append([y, x]) # 시작점 추가

	if d == 0:
		x = x + 1
	elif d == 1:
		y = y - 1
	elif d == 2:
		x = x - 1
	else:
		y = y + 1

	lst.append([y, x]) # 0세대 추가
	arr[y][x] = True

	for i in range(1, g+1):
		arrayRotate(lst, arr)

ANS = 0
# 정사각형 찾기
for i in range(100):
	for j in range(100):
		if arr[i][j] == True:
			ANS += squareFind(arr, i, j)

print(ANS)
