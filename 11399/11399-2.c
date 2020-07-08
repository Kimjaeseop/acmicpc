#include <stdio.h>
#include <limits.h>

// greedy // time out

int N;
long long MIN = LLONG_MAX;
int arr[1001];
int visit[1001];

void DFS(int V, int depth, int w, long long sum) // depth, weight // greedy
{
	if(depth == N && MIN > sum) {
		MIN = sum;
	}

	if(sum > MIN || depth >= N) {
		return ;
	}

	for(int i = 0; i < N; i++) {
		if (!visit[i] && (sum + (w + arr[i])) < MIN) {
			visit[i] = 1;
			DFS(i, depth + 1, w + arr[i], sum + (w + arr[i]));
			visit[i] = 0;
		}
	}

}

int main(void)
{
	//freopen("input.txt", "r", stdin);

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}

	for (int i = 0; i < N; i++) {
		visit[i] = 1;
		DFS(i, 1, arr[i], arr[i]);
		visit[i] = 0;
	}

	printf("%lld\n", MIN);

	return 0;
}
