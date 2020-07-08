#include <stdio.h>

int N;
int S;

int main(void)
{
	scanf("%d", &N);

	for (int i = 0; i < (2 * N) - 1; i++) {
		if (i < N) {
			S++;
		}
		else {
			S--;
		}

		for (int j = 0; j < S; j++) {
			printf("*");
		}
		printf("\n");
	}

	return 0;
}
