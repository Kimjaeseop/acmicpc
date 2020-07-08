#include <stdio.h>

int fact(int n, int sum)
{
	if (n==0)
		return sum;
	else
		return fact(n-1, sum*n);
}

int main(void)
{
	int N;

	scanf("%d", &N);

	printf("%d\n", fact(N, 1));

	return 0;
}
