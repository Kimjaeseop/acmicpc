#include <stdio.h>

int A, I;

int main(void)
{
	scanf("%d %d", &A, &I);

	printf("%d\n", (A * (I-1)) + 1);

	return 0;
}
