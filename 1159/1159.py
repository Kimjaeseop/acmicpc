import sys
#input = sys.stdin.readline

sys.stdin = open('input.txt', 'r')

N = int(input())
dic = {}

for _ in range(N):
	name = input()
	if name[0] in dic.keys():
		dic[name[0]] += 1
	else:
		dic[name[0]] = 1

ANS = [key for key, value in dic.items() if value >= 5]

# 굳이 len(ANS)==0 작업 필요 X
# 리스트 출력시엔 end X sep으로 구분자를 지정
if ANS:
	print(*sorted(ANS), sep='') # 정렬된 데이터 출력하는 법
else:
	print('PREDAJA')



