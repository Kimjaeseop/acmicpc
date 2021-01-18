#include <iostream>
#include <algorithm>
#include <queue>
#include <deque>
#include <unistd.h>

// fail

using namespace std;

int T, k, N;
char C;
int cnt;
deque<int> dq;

int main(void)
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen("input.txt", "r", stdin);

	cin >> T;

	while (T--) {
		cin >> k;
		cnt = 0;

		for (int i = 0; i < k; i++) {
			cin >> C >> N;

			if (C == 'I') {
				dq.push_back(N);
				cnt++;
			}
			else if (C == 'D' && cnt > 0){
				sort(dq.begin(), dq.end());

				if (N == 1)
					dq.pop_back();
				else
					dq.pop_front();

				cnt--;
			}
		}
		if (dq.empty()) {
			cout << "EMPTY" << "\n";
			continue;
		}

		cout << dq.back() << " ";
		cout << dq.front() << "\n";

		while (!dq.empty())
			dq.pop_back();
	}

	return 0;
}
