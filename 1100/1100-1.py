import sys

sys.stdin = open('input.txt', 'r')

r = ''
# 이렇게하면 매 문자열 뒤에 0이 붙어서 모든줄의 length가 9줄이 되어서
# 2칸씩 이동하면서 세면된다.
for _ in range(8):
	r += input() + '0'

# count로 list slicing의 결과를 count 가능
print(r[::2].count('F'))
