#include <stdio.h>

int arr[1001];
int N, A, CNT;

int main(void)
{
	arr[1] = 1;

	for (int i = 2; i < 1000; i++) {
		for (int j = 2; ; j++) {
			if (i * j > 1000)
				break;

			arr[i * j] = 1;
		}
	}

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &A);

		if (!arr[A])
			CNT++;
	}

	printf("%d\n", CNT);

	return 0;
}


 
