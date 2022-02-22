#include <cstdio>
#include <queue>

using namespace std;

int F, S, G, U, D;
int visited[1000001];

int BFS()
{
	queue<int> Q;
	int step, length, curLocation, find;

	step = length = curLocation = find = 0;

	Q.push(S);

	while (!Q.empty() && !find) {
		step++;
		length = Q.size();

		while (length--) {
			curLocation = Q.front();
			Q.pop();

			//printf("curLocation : %d\n", curLocation);

			if (curLocation == G) {
				find = 1;
				break;
			}

			if (curLocation + U <= 1000000 && !visited[curLocation+U] && curLocation + U <= F) {
				Q.push(curLocation+U);
				visited[curLocation+U] = 1;
			}

			if (curLocation - D > 0 && !visited[curLocation-D]) {
				Q.push(curLocation-D);
				visited[curLocation-D] = 1;
			}
		}
		//printf("=======================\n");
	}

	return find == 1 ? step-1 : -1;
}

int main(void)
{
	int result;

	//freopen("input_1.txt", "r", stdin);

	scanf("%d %d %d %d %d", &F, &S, &G, &U, &D);

	if ((result = BFS()) != -1) {
		printf("%d\n", result);
	}
	else {
		printf("use the stairs\n");
	}

	return 0;
}
	
