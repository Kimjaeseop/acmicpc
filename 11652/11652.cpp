#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

long long arr[1000001];
long long ans;
int ans_cnt;
int cnt;

int main(void)
{
	int N;
	long long tmp;

	scanf("%d", &N);

	for (int i=0; i<N; i++) {
		scanf("%lld", &tmp);
		arr[i]=tmp;
	}

	sort (arr, arr+N);

	ans = arr[0]; // 같은 수라면 가장 작은 값을 출력한다.

	for (int i=1; i<N; i++) {
		if (arr[i]==arr[i-1])
			cnt++;
		else
			cnt=0;

		if (ans_cnt < cnt) {
			ans_cnt=cnt;
			ans=arr[i];
		}
	}

	printf("%lld\n", ans);

	return 0;
}


