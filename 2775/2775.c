#include <stdio.h>
#include <string.h>

int arr[15][15];
int T, K, N;
int ANS;

int main(void)
{
	scanf("%d", &T);

	for (int i=1; i<=14; i++) {
		arr[0][i]=i;
		arr[1][i]=i;
	}

	for (int i=0; i<T; i++) {
		scanf("%d %d", &K, &N);

		for (int j=2; j<=K; j++) {
			for (int p=1; p<=N; p++) {
				for (int q=1; q<=p; q++) {
					arr[j][p] += arr[j-1][q];
				}
			}
		}

		for (int j=1; j<=N; j++)
			ANS += arr[K][j];

		printf("%d\n", ANS);
		ANS = 0;

		for (int i=2; i<=K; i++) {
			memset(arr[i], 0, sizeof(int)*15);
		}
	}

	return 0;
}
