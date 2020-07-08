#include <stdio.h>

int A, B, C;

int main(void)
{
	while (1) {
		scanf("%d %d %d", &A, &B, &C);

		if (!A && !B && !C)
			break;

		A *= A; B *= B; C *= C;

		if (A >= B && A >= C && A == B + C)
			printf("right\n");
		else if (B >= A && B >= C && B == A + C)
			printf("right\n");
		else if (C >= A && C >= B && C == B + A)
			printf("right\n");
		else
			printf("wrong\n");
	}

	return 0;
}
