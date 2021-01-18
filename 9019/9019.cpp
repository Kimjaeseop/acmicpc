#include <iostream>
#include <queue>
#include <utility>
#include <string>
#include <string.h>

using namespace std;

// 123 L -> 1230
// 123 R -> 3012

int main(void)
{
	int N, A, B;

	//freopen("input.txt", "r", stdin);

	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		queue<pair<int, string>> Q;
		vector<bool> check(10000, 0);
		cin >> A >> B;

		Q.push({A, ""});

		while (!Q.empty()) {
			if (Q.front().first == B) {
				cout << Q.front().second << endl;
				break;
			}

			pair <int, string> tmp_pair = Q.front();
			Q.pop();

			int t_1 = tmp_pair.first * 2 % 10000;
			int t_2 = tmp_pair.first == 0 ? 9999 : tmp_pair.first - 1;
			int t_3 = (tmp_pair.first % 1000) * 10 + (tmp_pair.first / 1000);
			int t_4 = (tmp_pair.first / 10) + ((tmp_pair.first % 10) * 1000);

			if (check[t_1] == 0) {
				Q.push({t_1, tmp_pair.second+"D"});
				check[t_1] = 1;
			}
			
			if (check[t_2] == 0) {
				Q.push({t_2, tmp_pair.second+"S"});
				check[t_2] = 1;
			}

			if (check[t_3] == 0) {
				Q.push({t_3, tmp_pair.second+"L"});
				check[t_3] = 1;
			}

			if (check[t_4] == 0) {
				Q.push({t_4, tmp_pair.second+"R"});
				check[t_4] = 1;
			}
		}
	}

	return 0;
}

	
