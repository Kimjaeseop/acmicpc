#include <iostream>
#include <string>
#include <map>

using namespace std;

// 옷의 종류만 중요할 뿐 옷의 이름은 중요하지 않다
// 해당 카테고리의 물건을 입지 않았을 경우, 알몸인 경우를 고려하면 된다.
// 1. 해당 카테고리의 물건을 입지 않은 경우
// 카테고리가 총 3개로 a, b, c가 있고 각 1, 2, 3개가 들어왔다고 가정하면
// a bb ccc에서 입지 않은 경우 0을 고려하여 a0 bb0 ccc0이 된다
// 예를 들어 a00이 뽑히면 a만 입은 경우가 되는 것
// 모든 경우의 수를 고려하려면 ANS *= (arr[N] + 1)
// 2. 알몸인 경우
// 000이 뽑힌 경우를 빼주면 된다 ANS-1

int main(void) {
	int N, M;
	int ANS;
	string a, b;

	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);

	freopen("input_1.txt", "r", stdin);

	cin >> N;

	while (N--) {
		map<string, int> m;
		ANS = 1;
		cin >> M;

		for (int i = 0; i < M; i++) {
			cin >> a >> b;
			m[b]++;
		}

		for (auto it = m.begin(); it != m.end(); it++) {
			ANS *= it->second + 1; 
		}

		cout << ANS-1 << endl;
	}

	exit(0);
}
