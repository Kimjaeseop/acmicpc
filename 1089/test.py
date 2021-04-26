import sys
si = sys.stdin.readline
elev, possibleNums = [], []
nums = [set() for _ in range(10)]
nums[0] = {0, 1, 2, 3, 5, 6, 8, 9, 11, 12, 13, 14}
nums[1] = {2, 5, 8, 11, 14}
nums[2] = {0, 1, 2, 5, 6, 7, 8, 9, 12, 13, 14}
nums[3] = {0, 1, 2, 5, 6, 7, 8, 11, 12, 13, 14}
nums[4] = {0, 2, 3, 5, 6, 7, 8, 11, 14}
nums[5] = {0, 1, 2, 3, 6, 7, 8, 11, 12, 13, 14}
nums[6] = {0, 1, 2, 3, 6, 7, 8, 9, 11, 12, 13, 14}
nums[7] = {0, 1, 2, 5, 8, 11, 14}
nums[8] = {0, 1, 2, 3, 5, 6, 7, 8, 9, 11, 12, 13, 14}
nums[9] = {0, 1, 2, 3, 5, 6, 7, 8, 11, 12, 13, 14}
 
 
def check(idx, pos):
    temp = set()
    for c in range(3):
        for r in range(5):
            if elev[r][idx+c] == '#':
                temp.add(r*3+c)
    for i in range(10):
        if nums[i].intersection(temp) == temp:
            possibleNums[pos].append(i)
 
 
def main():
    global elev, possibleNums
 
    n = int(si())
    elev, possibleNums = [si()[:-1] for _ in range(5)], [[] for _ in range(n)]
    for i in range(n):
        idx = 4*i
        check(idx, i)
 
    total, pnlist = 1, []
    for i, e in enumerate(possibleNums):
        total *= len(e)
        s = 0
        for elem in e:
            s += elem
        pnlist.append([s*10**(n-i-1), len(e)])
    if not total:
        print(-1)
        return
 
    s = 0
    for e in pnlist:
        s += e[0]*total//e[1]
    print(s/total)
 
 
if __name__ == '__main__':
    main()
