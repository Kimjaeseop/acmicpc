#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<long long> V;

int main(void)
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M, in;

	//freopen("input_3.txt", "r", stdin);

	cin >> N >> M;

	for (int i = 0; i < N + M; i++) {
		cin >> in;
		V.push_back(in);
	}

	sort(V.begin(), V.end());

	for (auto iter : V) {
		cout << iter << " ";
	}

	return 0;
}
