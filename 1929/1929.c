#include <stdio.h>

int M, N;
int ans[1000001];

int main(void)
{
	scanf("%d %d", &M, &N);
	ans[1]=1;

	for (int i=2; i<=N; i++)
		for (int j=2; i*j<=N; j++)
			ans[i*j]=1;

	for (int i=M; i<=N; i++) 
		if (ans[i]==0)
			printf("%d\n", i);

	return 0;
}
