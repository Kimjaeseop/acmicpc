import sys

N = int(input())
crane = sorted(list(map(int, input().split())), reverse=True)

M = int(input())
box = sorted(list(map(int, input().split())), reverse=True)

if crane[0] < box[0]:
	print(-1)
	sys.exit()

answer = 0

# 크레인은 들 수 있는 무게를 최대로 들어야 한다
while box:
	for c in crane: # while을 돌면서 크레인을 계속 순회 # ex) 크레인이 3개라면 0~2를 계속 순회해서 n번 크레인이 들 수 있는 가장 무거운 무게를 배치
		for i in range(len(box)):
			if c >= box[i]: # 내림차순으로 정렬되어 있기 때문에 c >= box[i]는 크레인이 들 수 있는 가장 큰 무게
				box.pop(i)
				break
	# 여기로 왔을 땐 각 크레인에 가장 무거운 무게의 박스가 배정되어 있다.
	answer += 1

print(answer)
