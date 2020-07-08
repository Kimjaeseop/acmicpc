#include <stdio.h>
#include <algorithm>
#include <queue>
#include <tuple>
#include <iostream>
#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>

using namespace std;

int N, M;
int arr[1004][1004]={0,};
int dir[4][2] {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

void BFS(void);
 
// input1 : 15
// input2 : -1
// input3 : 29
// input4 : 1
// input5 : 20
// input6 : 10
// input7 : 6
// input8 : 3
// input9 : 13
// input10 : 5
// input11 : 7
// input12 : 39
// input13 : 18
// input14 : 5

int main(int argc, char *argv[])
{
	freopen(argv[1], "r", stdin);
	scanf("%d %d\n", &N, &M);

	for (int i=0; i<=N+1; i++)
		for (int j=0; j<=M+1; j++)
			arr[i][j]=-1;

	for (int i=1; i<=N; i++)
		for (int j=1; j<=M; j++)
			scanf("%1d", &arr[i][j]);

	BFS();

	return 0;
}

void BFS(void)
{
	int depth=0;
	bool visited[N+1][M+1][2]={0,};

	queue <tuple<int, int, int> > q;

	q.push(make_tuple(1, 1, 0));
	visited[1][1][0]=1;

	while (!q.empty()) {
		depth++;
		int size = q.size();

		for (int s=0; s<size; s++) {
			if (get<0>(q.front()) == N && get<1>(q.front()) == M) {
				printf("%d\n", depth);
				exit(0);
			}
			for (int i=0; i<4; i++) {
				int a=dir[i][0] + get<0>(q.front());
				int b=dir[i][1] + get<1>(q.front());
				//printf("%d ==  a : %d, b: %d\n", s*4+i, a, b);
				if (!(0<a && a<=N && 0<b && b<=M))
					continue;

				if (!get<2>(q.front())) {
					if (arr[a][b]==0 && !visited[a][b][0]) {
						q.push(make_tuple(a, b, 0));
						visited[a][b][0]=1;
					}
					if (arr[a][b]==1 && !visited[a][b][1]) {
						q.push(make_tuple(a, b, 1));
						visited[a][b][1]=1;
					}
				}
				else {
					if (arr[a][b]==1)
						continue;
					if (arr[a][b]==0 && !visited[a][b][1]) {
						q.push(make_tuple(a, b, 1));
						visited[a][b][1]=1;
					}
				}
			}
			q.pop();
		}
	}

	if (!visited[N][M][0] && !visited[N][M][1])
		printf("-1\n");
}
