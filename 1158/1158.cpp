#include <iostream>
#include <queue>

using namespace std;

queue <int> Q;
int N, K;
int i;
int tmp;

int main(void)
{
	//freopen("input.txt", "r", stdin);

	scanf("%d %d", &N, &K);

	for (int i=1; i<=N; i++)
		Q.push(i);

	printf("<");

	while (!Q.empty()) {
		i++;

		if (i==K) {
			if (Q.size()!=N)
				printf(", ");
			printf("%d", Q.front());
			Q.pop();
			i=0;
		}
		else {
			Q.push(Q.front());
			Q.pop();
		}
	}

	printf(">");

	return 0;
}
