import sys

# https://www.acmicpc.net/source/17374413
# 코드 참고하자 ...

#sys.stdin = open('input.txt', 'r')

l, r = input(), input()

h1, m1, s1 = int(l[0:2]), int(l[3:5]), int(l[6:8])
h2, m2, s2 = int(r[0:2]), int(r[3:5]), int(r[6:8])

time1 = (h1*60*60) + (m1*60) + s1
time2 = (h2*60*60) + (m2*60) + s2

if time1 == time2:
	print('24:00:00')
	sys.exit()

if time1 > time2:
	time2 += 86400 # 하루 -> 초

time2 -= time1

s = time2 % 60
time2 -= s

h = time2 // 3600
time2 -= h * 3600

m = time2 // 60

#print(f"{h}:{m}:{2s}")
print('%02d:%02d:%02d' %(h, m, s))
