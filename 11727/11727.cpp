#include <stdio.h>

int main (void)
{
	int N;
	int arr[1001] = {0,};

	scanf("%d", &N);

	arr[0]=0;
	arr[1]=1;
	arr[2]=3;
	arr[3]=5;

	//n=2
	// || = ¤± 3
	//n=3
	// ¤±| |¤± ||| =| |= 5

	// n = n-1 + (n-2)*2;
	for (int i=4; i<=N; i++)
		arr[i]=(arr[i-1]+(arr[i-2]*2))%10007;

	printf("%d\n", arr[N]);

	return 0;
}

	
