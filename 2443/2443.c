#include <stdio.h>

int main(void)
{
	int N;

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 2*N-1-i; j++) { 
			if (j >= i)
				printf("*");
			else
				printf(" ");
		}
		printf("\n");
	}
	return 0;
}
