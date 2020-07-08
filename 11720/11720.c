#include <stdio.h>

int sum;
int in;
int N;

int main(void)
{
	scanf("%d", &N);

	scanf("%d", &in);

	for(int i = 0; i < N; i++) {
		sum += (in % 10);
		in /= 10;
	}

	printf("%d\n", sum);

	return 0;
}
