import sys
#input = sys.stdin.readline

sys.stdin = open('input.txt', 'r')

month_dict = {'January':31,
'February':28,
'March':31,
'April':30,
'May':31,
'June':30,
'July':31,
'August':31,
'September':30,
'October':31,
'November':30,
'December':31}

month, day, year, time = map(str, input().split())
hour, minute = map(int, time.split(':'))
day = day.replace(',', '')

day = int(day)
year = int(year)

monthsec = 0
yearsec = 24*60*60
yoonyear = 1 if year%400==0 or (year%4==0 and year%100!=0) else 0
yearsec *= 365 if yoonyear == 0 else 366

for i, p in enumerate(month_dict):
	if p == month:
		break

	if yoonyear == 1 and p == 'February':
		monthsec += 1

	monthsec += month_dict[p]

# 하루가 다 지난 것이 아니므로 하루 빼줌
monthsec += (day - 1)

monthsec *= (24*60*60)
ans = (minute*60) + (hour*60*60) + monthsec

#print('%.9f' %((ans/yearsec)*100))
print(ans*100/yearsec)
