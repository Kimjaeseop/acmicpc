#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <cmath>

using namespace std;

long long ans;
int N;
vector<pair<int, int>> V;

int main(void)
{
	int in;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> in;
		V.push_back({in, i});
	}

	sort(V.begin(), V.end());

	for (int i = 0; i < N; i++) 
		ans += abs(V[i].second - i);

	cout << ans << endl;

	return 0;
}


