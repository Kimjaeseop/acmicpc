#include <iostream>
#include <vector>

using namespace std;

vector<bool> V(20000002);
int N, M, in;

int main(void)
{
	freopen("input.txt", "r", stdin);

	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> in;
		V[in < 0 ? -in+10000001 : in] = true;
	}

	cin >> M;

	for (int i = 0; i < M; i++) {
		cin >> in;
		cout << V[in < 0 ? -in+10000001 : in] << " ";
	}

	return 0;
}
