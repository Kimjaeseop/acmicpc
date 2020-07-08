#include <stdio.h>

int main (void)
{
	int N;
	int arr[1001]={0,};

	scanf("%d", &N);

	arr[0]=0;
	arr[1]=1;
	arr[2]=2;

	// n==1
	// |
	// n==2
	// || =
	// n==3 (n==1 + n==2)
	// |= =| ||| 

	for (int i=3; i<=N; i++)
		arr[i]=(arr[i-1]+arr[i-2])%10007;

	printf("%d\n", arr[N]);

	return 0;
}
