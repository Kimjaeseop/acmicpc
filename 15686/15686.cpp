#include <iostream>
#include <utility>
#include <vector>
#include <cstdlib>
#include <algorithm>

using namespace std;

vector<pair<int, int>> house;
vector<pair<int, int>> store;
vector<int> tmp;

int store_size, house_size;
int N, M;
int MIN = 2100000000;

int main(void)
{
	int in;
	int sum, ans;

	freopen("input_4.txt", "r", stdin);

	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> in;

			if (in == 1) {
				house.push_back({i, j});
				house_size++;
			}
			else if (in == 2) {
				store.push_back({i, j});
				store_size++;
			}
		}
	}

	// next_permutation을 위해 유효한 치킨 집을 뽑기 위한 배열 준비 작업
	// example) 5개의 치킨집 중 3개만 뽑는다고 가정하면
	// 00111배열을 만들어서 모든 조합의 수를 뽑아서 치킨집의 인덱스로 활용하면 모든 경우의 치킨집 조합을 고려할 수 있다.
	for (int i = 0; i < store_size - M; i++) 
		tmp.push_back(0);

	for (int i = 0; i < M; i++)
		tmp.push_back(1);

	do {
		ans = 0;
		int calc;

		for (int i = 0; i < house_size; i++) {
			sum = 2100000000;
			for (int j = 0; j < store_size; j++) { // 각 집별로 가까운 치킨집을 뽑는다
				if (tmp[j]) { // 유효한 치킨집이라면
					calc = abs(house[i].first-store[j].first) + abs(house[i].second - store[j].second);

					if (sum > calc) // 가까운 치킨집인지 비교
						sum = calc;
				}
			}
			ans += sum;
		}

		if (ans < MIN) // 뽑은 치킨집이 최소 거리를 갖는지 비교
			MIN = ans;

	} while (next_permutation(tmp.begin(), tmp.end()));

	cout << MIN << endl;

	return 0;
}
