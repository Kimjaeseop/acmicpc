#include <iostream>
#include <queue>

using namespace std;

typedef struct {
	int cur; int k;
} node;

int N, x, y;
bool arrive;

int main(void)
{
	int size, depth;

	freopen("input_1.txt", "r", stdin);

	cin >> N;

	while (N--) {
		cin >> x >> y;

		arrive = depth = 0;
		queue<node> Q;

		Q.push({x, 0});

		while (!arrive) {
			size = Q.size();
				
			while (size--) {
				int curLocate = Q.front().cur;
				int k = Q.front().k;
				Q.pop();

				if (curLocate == y-1 && (k-1 == 1 || k == 1 || k+1 == 1)) {
					cout << depth + 1 << endl;
					arrive = true;
					break;
				}

				if (curLocate+k-1 > 0)
					Q.push({curLocate+k-1, k-1});

				Q.push({curLocate+k, k});
				Q.push({curLocate+k+1, k+1});
			}
			depth++;
		}
	}

	return 0;
}

		

