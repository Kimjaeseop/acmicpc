W, H, f, c, x1, y1, x2, y2 = map(int, input().split())

lst = []
count = (x2-x1) * (y2-y1)

for x in range(x1+f, x2+f):
	for y in range(y1, y2):
		i, j = (W-f)-x, y

		if i >= 0:
			count += 1

print((W*H)-(count * (c+1)))
