arr = [True for _ in range(250000)]
arr[0] = arr[1] = False

for i in range(2, 250000):
	j = 2

	while i*j < 250000:
		arr[i*j] = False
		j += 1

while True:
	N = int(input())

	if N == 0:
		break

	print(sum(arr[N+1:(2*N)+1]))
	
