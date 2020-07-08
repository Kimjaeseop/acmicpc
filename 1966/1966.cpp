#include <iostream>
#include <queue>

using namespace std;

// 단순한 연산으로 풀 수 있을 줄 알았다,,,
// 같은 중요도의 수를 세서 저장하기도 했지만 잘못된 방향이었고
// 그냥 정석대로 풀어도 풀리는 문제
// 입력가능한 수의 범위가 작아서 시간 초과가 나지 않고 가능

priority_queue <int> pq;
queue <pair<int, int>> q;
int T, N, M;
int in;
int cnt;

int main(void)
{
	freopen("input.txt", "r", stdin);

	scanf("%d", &T);

	for (int i = 0; i < T; i++) {
		scanf("%d %d", &N, &M);

		for (int j = 0; j < N; j++) {
			scanf("%d", &in);
			pq.push(in);
			q.push({in, j});
		}

		while (1) {
			int f = q.front().first;
			int s = q.front().second;

			q.pop();

			if (s == M && f == pq.top()) { // 우선순위 큐의 top이고 현재 찾는 수라면 출력
				printf("%d\n", cnt + 1); // 우선순위의 top이 아니라면 자기보다 큰 수가 남아있다는 뜻
				break;
			}
			else if (f == pq.top()) { // 큐, 우선순위 큐의 맨 위 숫자가 같다면 우선순위 큐 pop (출력)
				pq.pop(); 
				cnt++;
			}
			else { // 모두 아니면 q의 수를 맨 뒤로 이동
				q.push({f, s});
			}
		}
		cnt = 0;
		while (!q.empty()) q.pop();
		while (!pq.empty()) pq.pop();
	}

	return 0;
}
