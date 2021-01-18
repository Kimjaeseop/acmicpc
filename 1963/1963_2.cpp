#include <iostream>
#include <queue>

using namespace std;

int N, A, B, depth, break_check;
int digit[4], arr[10001];

int main(void)
{
	freopen("input.txt", "r", stdin);
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	arr[1] = 1;

	for (int i = 2; i < 10000; i++) {
		for (int j = 2; ; j++) {
			if (i * j > 10000)
				break;

			arr[i * j] = 1;
		}
	}

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> A >> B;
		int check[10001] = {0, };
		depth = break_check = 0;

		queue<int> Q;

		Q.push(A);
		check[A] = 1;

		while (1) {
			int S = Q.size();

			for (int l = 0; l < S; l++) {
				if (Q.front() == B) {
					break_check = 1;
					break;
				}

				int T = Q.front();
				Q.pop();

				for (int i = 3; i >= 0; i--) {
					digit[i] = T % 10;
					T /= 10;
				}


				digit[0] *= 1000; digit[1] *= 100; digit[2] *= 10;
				int d_c[4]; // duplicate check

				for (int i = 0; i < 10; i++) {
					d_c[0] = (digit[0]+digit[1]+digit[2]+i);
					d_c[1] = (digit[0]+digit[1]+(i*10)+digit[3]);
					d_c[2] = (digit[0]+(i*100)+digit[2]+digit[3]);
					d_c[3] = ((i*1000)+digit[1]+digit[2]+digit[3]);

					for (int j = 0; j < 4; j++) {
						if (d_c[j] < 1000 || d_c[j] > 10000 || arr[d_c[j]] || check[d_c[j]])
							continue;

						check[d_c[j]] = 1;
						Q.push(d_c[j]);
					}
				}
			}

			if (Q.front() == B) {
				if (break_check)
					cout << depth << endl;
				else
					cout << depth + 1 << endl;
				// 같은 depth의 노드 중 가장 왼쪽의 노드 // 한 depth의 추가 작업이 끝난 이후 다음 depth의 처음 노드
				// 해당 노드가 B와 같다면 depth가 증가되지 않은채 출력되는 경우를 방지
				break;
			}

			depth++;
		}
	}

	return 0;
}
