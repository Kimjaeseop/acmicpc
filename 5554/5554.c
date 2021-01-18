#include <stdio.h>

int N, T;

int main(void)
{
	for (int i = 0; i < 4; i++) {
		scanf("%d", &T);

		N += T;
	}

	printf("%d\n%d\n", N / 60, N % 60);

	return 0;
}
