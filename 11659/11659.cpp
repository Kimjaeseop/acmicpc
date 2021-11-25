#include <stdio.h>

int main(void)
{
	int N, M, a, b;
	unsigned short num;
	unsigned short arr[100001] = {0, };

	//freopen("input_1.txt", "r", stdin);

	scanf("%d %d", &N, &M);

	for (int i = 1; i <= N; i++) {
		scanf("%hu", &num);
		arr[i] = arr[i-1] + num;
	}

	for (int i = 0; i < M; i++) {
		scanf("%d %d", &a, &b);

		printf("%hu\n", arr[b]-arr[a-1]);
	}

	return 0;
}
