#include <stdio.h>

int N, M;
int A, B;
short chk[1001][1001];
short node[1001];

int CNT;

void BFS(int T)
{
	node[T] = 1;

	for(int i = 1; i <= N; i++) {
		if(chk[T][i] && !node[i]) { // chk를 지워줄 필요가 없는게 시작점(node)에 체크를하면 같은 점은 다시 시작되지 않음
			BFS(i);
		}
	}
}

int main(void)
{
	freopen("input2.txt", "r", stdin);

	scanf("%d %d", &N, &M);

	for (int i = 0; i < M; i++) {
		scanf("%d %d", &A, &B);

		chk[A][B] = 1; // 비방향성
		chk[B][A] = 1;
	}

	for (int i = 1; i <= N; i++) {
		if(!node[i]) { // 어차피 해당 노드로 시작하는 점은 다 지우기 때문에 시작점으로만 체크해도 된다
			BFS(i);
			CNT++;
		}
	}

	printf("%d\n", CNT);

	return 0;
}
