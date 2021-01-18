from datetime import datetime

# Febraury -> %B
# feb -> %b

# Date 입력
# strptime : string to datetime
# strftime : time to string
now = datetime.strptime(input(), '%B %d, %Y %H:%M')
start = datetime(now.year, 1, 1)
end = datetime((now.year+1), 1, 1)

# :.20 -> 길이
# 입력 - 입력년도의 시작점 : 입력년도의 1월 1일부터 지난 초
# 끝 - 입력년도의 시작점 : 입력년도의 다음년도 1월 1일은 입력년도의 12월 31일 23:59:59+1초임으로 end - start는 입력년도의 총 초를 나타낸다
print(f"{(now-start)/(end-start)*100:.20}")
