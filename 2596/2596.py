import sys

def diffCount(str1, str2):
	cnt = 0
	for i in range(6):
		if str1[i] != str2[i]:
			cnt+=1
	
	return cnt

def minCount(arr):
	cnt = 0
	for i in arr:
		if min(arr) == i:
			cnt+=1

	return cnt

start = 0
end = 6
N = 0

dic = {'000000' : 'A',
	'001111' : 'B',
	'010011' : 'C',
	'011100' : 'D',
	'100110' : 'E',
	'101001' : 'F',
	'110101' : 'G',
	'111010' : 'H'}

N = int(input())
s = input()

ans = ''

for i in range(0, N*6, 6):
	sub_str = s[start + i : end + i]
	if sub_str in dic.keys():
		ans += dic[sub_str]
	else:
		cnt = 0
		idx = 0
		arr = []

		for key in dic.keys():
			arr.append(diffCount(sub_str, key))

		if minCount(arr) != 1:
			print(int(i/6) + 1)
			sys.exit()
		else:
			ans += list(dic.values())[arr.index(min(arr))] # dict values to list
# 차이가 가장 작은 지점의 인덱스를 뽑아서 딕셔너리로 접근 후 문자열에 붙임

print(ans)

		
