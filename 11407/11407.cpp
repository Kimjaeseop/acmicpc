#include <iostream>
#include <vector>

using namespace std;

int N, K;
int ANS;
vector<int> V;

// rbegin, rend 자꾸 까먹는다 벡터 값 반대로 출력 할 때 사용
// 딱히 어려운 부분 없고 최소의 경우를 구해야 하기 때문에 금액이 큰 수부터 나눠나가면 된다

int main(void)
{
	int in;

	//freopen("input_1.txt", "r", stdin);

	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		cin >> in;

		V.push_back(in);
	}

	for (auto it = V.rbegin(); it != V.rend(); it++) { // iterator를 사용하여 벡터 값 반대로 출력
		if ((K / *it) == 0)
			continue;
		ANS += (K / *it);
		K %= *it;
	}

	cout << ANS << endl;

	return 0;
}
