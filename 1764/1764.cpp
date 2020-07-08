#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

map <string, int> m;
int N, M;
string str;

vector <string> V;
int cnt;

int main(void)
{
	ios::sync_with_stdio(0);

	freopen("input.txt", "r", stdin);

	cin >> N >> M;

	for(int i = 0; i < N + M; i++) {
		cin >> str;

		m[str]++;
	}

	for (auto it = m.begin(); it != m.end(); it++) {
		if (it -> second == 2) {
			V.push_back(it -> first);
			cnt++;
		}
	}

	cout << cnt << endl;

	for (int i = 0; i < cnt; i++) {
		cout << V[i] << endl;
	}

	return 0;
}


