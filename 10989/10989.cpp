#include <stdio.h>

int N;
int tmp;
int arr[10001];

int main(void)
{

	//freopen("input.txt", "r", stdin);

	scanf("%d", &N);

	for (int i=0; i<N; i++) {
		scanf("%d", &tmp);
		arr[tmp]++;
	}

	for (int i=1; i<=10000; i++) 
		for (int j=0; j<arr[i]; j++)
			printf("%d\n", i);

	return 0;
}
