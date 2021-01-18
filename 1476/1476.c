#include <stdio.h>

int E, S, M;
int A, B, C, count;

int main(void)
{
	scanf("%d %d %d", &E, &S, &M);

	A = B = C = 1;

	count = 1;

	while (A != E || B != S || C != M) {
		if (A < 15) A++;
		else A = 1;

		if (B < 28) B++;
		else B = 1;

		if (C < 19) C++;
		else C = 1;

		count++;
	}

	printf("%d\n", count);

	return 0;
}


