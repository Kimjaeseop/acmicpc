#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>

using namespace std;

// pair<string, int> 벡터 하나로만 구현하려고 했으나
// index를 기준으로 찾을 때 O(1)을 포기하는 것보다
// 벡터 두 개를 유지하는 것이 낫다고 생각되서 벡터 두 개로 유지

vector <string> V; // index를 기준으로 찾을 때
vector <pair<string, int>> A; // 문자열을 기준으로 찾을 때
string str;
int l, r, mid;

int N, M;
int num;

int main(void)
{
	ios_base :: sync_with_stdio(0);
	 
	freopen("input.txt", "r", stdin);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> str;

		V.push_back(str);
		A.push_back({str, i});
	}

	sort(A.begin(), A.end());

	for (int i = 0; i < M; i++) {
		cin >> str;

		if (str[0] >= '0' && str[0] <= '9') {
			cout << V[stoi(str) - 1] << endl;
		}
		else {
			l = 0;
			r = N;

			while (l <= r) {
				mid = (l + r) / 2;

				if(str <= A[mid].first) {
					r = mid - 1;

					if (str == A[mid].first) {
						cout << A[mid].second + 1 << endl;
						break;
					}
				}
				else if (str > A[mid].first) {
					l = mid + 1;
				}
			}
		}
	}

	return 0;
}




