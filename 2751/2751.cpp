#include <stdio.h>
#include <stdlib.h>

int input[1000001];

int compare(const void *a, const void *b)
{
	int num1 = *(int *)a;
	int num2 = *(int *)b;

	if (num1 < num2)
		return -1;
	if (num1 > num2)
		return 1;

	return 0;
}

int main(void)
{
	int N;

	scanf("%d", &N);

	for (int i=0; i<N; i++)
		scanf("%d", &input[i]);

	qsort(input, N, sizeof(int), compare);

	for (int i=0; i<N; i++)
		printf("%d\n", input[i]);

	return 0;
}
