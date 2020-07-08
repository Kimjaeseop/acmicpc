#include <stdio.h>

#define MAX(A, B) ((A > B) ? A : B)
#define MIN(A, B) ((A < B) ? A : B)

int main(void)
{
	int N;
	int max=-1000000, min=1000000;
	int arr[1000001]={0,};

	scanf("%d", &N);

	for (int i=0; i<N; i++) {
		scanf("%d", &arr[i]);

		max = MAX(max, arr[i]);
		min = MIN(min, arr[i]);
	}

	printf("%d %d\n", min, max);

	return 0;
}



