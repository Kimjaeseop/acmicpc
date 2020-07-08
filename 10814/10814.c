#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int age;
	char name[101];
} input;

input arr[100001];

int compare (const void *a, const void *b)
{
	input tmp1 = *(input *)a;
	input tmp2 = *(input *)b;

	if (tmp1.age < tmp2.age)
		return -1;
	if (tmp1.age > tmp2.age)
		return 1;

	return 0;
}

int main(void)
{
	int N;

	scanf("%d", &N);

	for (int i=0; i<N; i++)
		scanf("%d %s", &(arr[i].age), arr[i].name);

	qsort(arr, N, sizeof(input), compare);

	for (int i=0; i<N; i++)
		printf("%d %s\n", arr[i].age, arr[i].name);

	return 0;
}
