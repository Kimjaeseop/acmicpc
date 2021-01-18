#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

vector<string> V(20001);

bool comp(string a, string b)
{
	if (a.length() != b.length())
		return a.length() < b.length();

	return a < b;
}

int main(void)
{
	int N;

	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen("input.txt", "r", stdin);

	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> V[i];

	sort(V.begin(), V.begin() + N, comp);

	for (int i = 0; i < N; i++) {
		if (V[i] != V[i+1])
			cout << V[i] << '\n';
	}

	return 0;
}
