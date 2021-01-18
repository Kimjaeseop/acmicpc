l, r = map(list, input().split())
# ['1', '2', '3'] ['4', '5']
# 1 * 4 + 1 * 5 + 2 * 4 + 2 * 4 + 3 * 5 + 4 * 5
# 1*(4+5) + 2*(4+5) + 3*(4+5)
# (1+2+3) * (4+5)
# map(func, list) -> func으로 list를 처리 -> int로 list를 캐스팅
print(sum(map(int, l))*sum(map(int,r)))
