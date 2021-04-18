import sys

N = int(input())
crane = sorted(list(map(int, input().split())), reverse=True)

M = int(input())
box = sorted(list(map(int, input().split())), reverse=True)

if crane[0] < box[0]:
	print(-1)
	sys.exit()

answer = 0

while box:
	for c in crane:
		for i in range(len(box)):
			if c >= box[i]: # 내림차순으로 정렬되어 있기 때문에 c >= box[i]는 크레인이 들 수 있는 가장 큰 무게
				box.pop(i)
				break
	
	answer += 1

print(answer)
