#include <iostream>
#include <stack>

using namespace std;

int T;
int N;

stack <int> S;

int in[1001];

int main(void)
{
	freopen("input.txt", "r", stdin);

	scanf("%d", &T);

	while (T--) {
		scanf("%d", &N);

		for (int i = 1; i <= N; i++) {
			scanf("%d", &in[i]);
		}

		int cnt = 0;

		for (int i = 1; i <= N; i++) {
			if (in[i] != 0) {
				S.push(in[i]);
				in[i] = 0;
				cnt++;
			}

			while(!S.empty()) {
				int tmp = S.top();
				S.pop();

				if (in[tmp] != 0) {
					S.push(in[tmp]);
					in[tmp] = 0;
				}
			}
		}
		printf("%d\n", cnt);
	}

	return 0;
}
