#include <iostream>
#include <algorithm>

using namespace std;

// 5 3
// 1 2 8 4 9
// 1 2 4 8 9
// 1 4 8 or 1 4 9

// 열심히 이해해보려고 했으나 역시 새로운 유형을 접하면 풀지 못한다,,
// 결국 검색해서 풀었는데, 거의 카피수준이지만 이해하려고 노력했다.

// 집 간 거리의 차이가 이분 탐색의 mid를 만족하고 그 개수가 C 이상이어야 한다.
// 그 중 최대를 뽑으면 되는데.

// 예제에서 차이를 1로 지정하면 물론 5개 전부 만족하기 때문에 정답 리스트에 존재 할 수 있다.
// 하지만 최대값이 아닌 것
// 때문에 mid를 늘리고 줄여가며 mid가 3이되면 거리 3을 만족하는 점 1 4 8 or 1 4 9가 존재하고 가능한 값중 최대값이
// 3이기 때문에 답은 3이된다.


int N, C;
int x[200001];

int func(int n)
{
	int cnt = 1, p = x[0];

	for (int i = 1; i < N; i++) {
		if (x[i] - p >= n) { // 현재지점이 과거 지점과 차이가 n을 만족하면
			cnt++; // 개수를 count하고
			p = x[i]; // 기준(현재)지점을 옮긴다
		}
	}

	return cnt >= C; // C 개수를 만족하는지 확인
}

int main(void)
{
	//freopen("input.txt", "r", stdin);

	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> C;

	for (int i = 0; i < N; i++)
		cin >> x[i];

	sort(x, x + N);

	int l = 1, r = 1000000000; // 집간 최대거리 지정

	while (l + 1 < r) { // l + 1로 탈출조건을 지정하지 않으면 탈출되지 못함
		int mid = (l + r) / 2;

		if (func(mid))
			l = mid;
		else
			r = mid;
	}

	cout << l << "\n";

	return 0;
}
