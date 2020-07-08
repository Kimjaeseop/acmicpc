#include <iostream>
#include <string>
#include <map>

using namespace std;

map <string, string> m;

int N, M;
string domain;
string pw;

// c++ map, 시간 4000ms 너무느리다.

int main(void)
{
	cin.tie(NULL);
	ios::sync_with_stdio(0);

	freopen("input.txt", "r", stdin);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> domain >> pw;

		m[domain] = pw;
	}

	for (int i = 0; i < M; i++) {
		cin >> domain;
		cout << m[domain] << endl;
	}

	return 0;
}
