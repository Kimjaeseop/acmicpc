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

		if (in > r) // 최대값 지정
			r = in;

		V.push_back(in);
	}

	l = 1;

	while (l <= r) {
		mid = (l + r) / 2;
		sum = 0;

		S = V.size();
		for (int i = 0; i < S; i++) {
			sum += (V[i] - mid < 0 ? 0 : V[i] - mid); // 집에 들고가는 나무가 양수이면 합을 구함
		}

		if (sum == M) { // 정확하게 같은 경우
			MAX = mid;
			break;
		}
		else if (sum < M) { // 합이 필요한 나무의 길이보다 작다면 최대 크기를 조정 // 덜 잘라야 함 // 미드 값이 작아져야 함
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
