#include <stdio.h>
#include <string.h>

long long arr[1000001];
int ans;

int main(void)
{
	int N;
	long long tmp;

	scanf("%d", &N);

	for (int i=0; i<N; i++) {
		scanf("%lld", &tmp);
		arr[i]=tmp;
	}

	tmp=0;

	for (int i=1; i<N; i++) {
		if (arr[i]==arr[i-1])
			tmp++;
		else
			tmp=0;

		if (tmp>ans)
			ans=tmp;
	}

	printf("%d\n", ans);

	return 0;
}


