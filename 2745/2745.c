#include <stdio.h>
#include <string.h>

long long arr[10001];
char N[32];
int B;
long long ans;
int len;

int main (void)
{
	//freopen("input.txt", "r", stdin);

	scanf("%s %d", N, &B);

	len = strlen(N);

	arr[0] = 1;

	for (int i=1; i<len; i++)
		arr[i] = arr[i-1] * B;

	for (int i=0; i<len; i++)
		ans += N[i]>='0' && N[i]<='9' ? arr[len-i-1]*(N[i]-'0') : arr[len-i-1]*(N[i]-'A'+10);

	printf("%lld\n", ans);

	return 0;
}

