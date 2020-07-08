#include <stdio.h>

int K;
int S[100001];
int top;
long long sum;

int main (void)
{
	freopen("input.txt", "r", stdin);

	scanf("%d", &K);

	for (int i=0; i<K; i++) {
		scanf("%d", &S[top++]);

		if (!S[top-1])
			top -= 2;
	}

	for (int i=0; i<top; i++)
		sum += S[i];

	printf("%lld\n", sum);

	return 0;
}
