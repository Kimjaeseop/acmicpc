#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>

using namespace std;

// pair<string, int> ���� �ϳ��θ� �����Ϸ��� ������
// index�� �������� ã�� �� O(1)�� �����ϴ� �ͺ���
// ���� �� ���� �����ϴ� ���� ���ٰ� �����Ǽ� ���� �� ���� ����

vector <string> V; // index�� �������� ã�� ��
vector <pair<string, int>> A; // ���ڿ��� �������� ã�� ��
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




