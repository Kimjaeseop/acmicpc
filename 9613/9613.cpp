#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> V;
int T, N;
int in;
long long ans;

// 벡터에 수를 담고 sort
// 유클리드 호제법으로 gcd 구한 이후 합

int gcd (int A, int B)
{
	return (A%B==0 ? B : gcd(B, A%B));
}

int main (void)
{
	//freopen("input.txt", "r", stdin);

	cin >> T;

	for (int i=0; i<T; i++) {
		cin >> N;

		V.clear();
		ans = 0;

		for (int j=0; j<N; j++) {
			cin >> in;

			V.push_back(in);
		}

		sort (V.begin(), V.end());

		for (int p=0; p<N; p++) {
			for (int q=p+1; q<N; q++) {
				ans += gcd (V[p], V[q]);
			}
		}

		cout << ans << endl;
	}

	return 0;
}

