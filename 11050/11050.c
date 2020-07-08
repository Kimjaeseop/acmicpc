#include <stdio.h>

int N, K;

int fact (int N)
{
	int sum=1;

	for (int i=N; i>0; i--)
		sum *= i;

	return sum;
}

int main(void) 
{
	scanf("%d %d", &N, &K);

	printf("%d\n", fact(N) / (fact(K) * fact(N-K)));

	return 0;
}
