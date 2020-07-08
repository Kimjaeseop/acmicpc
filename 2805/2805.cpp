#include <iostream>
#include <vector>

using namespace std;

int N, M;
int l, r, mid;
int S;
long long sum;
vector <int> V;
int in;
int MAX;

int main(void)
{
	//freopen("input.txt", "r", stdin);

	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++) {
		scanf("%d", &in);

		if (in > r)
			r = in;

		V.push_back(in);
	}

	l = 1;

	while (l <= r) {
		mid = (l + r) / 2;
		sum = 0;

		S = V.size();
		for (int i = 0; i < S; i++) {
			sum += (V[i] - mid < 0 ? 0 : V[i] - mid);
		}

		if (sum == M) {
			MAX = mid;
			break;
		}
		else if (sum < M) {
			r = mid - 1;
		}
		else if (sum >= M) {
			l = mid + 1;

			MAX = mid;
		}
	}

	printf("%d\n", MAX);

	return 0;
}
