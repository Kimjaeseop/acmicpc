T = int(input())

for _ in range(T):
	list_a_len, list_b_len = map(int, input().split())
	
	list_a = sorted(list(map(int, input().split())))
	list_b = sorted(list(map(int, input().split())))

	ans = 0
	count = 0
	list_a_idx = 0
	list_b_idx = 0

	while list_a_idx < list_a_len:
		print('a : ', list_a[list_a_idx] , ', b : ', list_b[list_b_idx])
		if list_a[list_a_idx] > list_b[list_b_idx]:
			count += 1
			list_b_idx += 1
			print('count : ', count)
		else:
			list_a_idx += 1
			ans += count

	print(ans)