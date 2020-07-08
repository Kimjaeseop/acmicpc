#include <stdio.h>

#define N 3

int arr[3];
int P, Q, M;
int ANS = 10000;

int main(void) {
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}

	scanf("%d %d", &P, &Q);

	M = (P < Q) ? P - 50 : Q - 50;

	for (int i = 0; i < N; i++) {
		arr[i] += M;

		if(arr[i] < ANS) {
			ANS = arr[i];
		}
	}

	printf("%d\n", ANS);

	return 0;
}

	
