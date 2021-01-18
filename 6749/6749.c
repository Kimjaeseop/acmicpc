#include <stdio.h>

int N_1, N_2;

int main(void)
{
	scanf("%d %d", &N_1, &N_2);

	printf("%d\n", N_2 + (N_2 - N_1));

	return 0;
}
