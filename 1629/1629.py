import math
import sys

a, b, c = map(int, input().split())

for i in range(b):
	print(math.pow(a, i))
	if math.pow(a, i) > b:
		print(int(math.pow(a, i) % c))
		sys.exit()

print(a%c)
		



