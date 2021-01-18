#include <stdio.h>

int T;
int N;

int main(void)
{
	for (int i = 0; i < 5; i++) {
		scanf("%d", &T);

		N += T;
	}

	printf("%d\n", N);

	return 0;
}

