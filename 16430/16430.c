#include <stdio.h>

int main(void)
{
	int A, B, P, Q;
	
	scanf("%d %d", &A, &B);
	P = B - A;
	Q = B;

	for (int i = 2; i <= 9; i++) {
		if (P % i == 0 && Q % i == 0) {
			P /= i; Q /= i;
		}
	}

	printf("%d %d\n", P, Q);

	return 0;
}
