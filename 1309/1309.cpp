#include <stdio.h>

int arr[100001];

// N : 0, 1
// N : 1, 1 + 2
// N : 2, 1 + 4 + 2 (중복 X)

int main (void)
{
	int N;

	scanf("%d", &N);

	arr[0]=1;
	arr[1]=3;

	for (int i=2; i<=N; i++)
		arr[i]=(arr[i-2]+(arr[i-1]*2))%9901;

	printf("%d\n", arr[N]);

	return 0;
}


