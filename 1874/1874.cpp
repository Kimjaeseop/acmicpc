#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int N;
int in;
stack <int> S;
queue <char> Q;


int main(void)
{
	freopen("input2.txt", "r", stdin);

	scanf("%d", &N);

	for (int i = 1, j = 1; i <= N; i++) {
		scanf("%d", &in);

		for (; j <= in; j++) {
			S.push(j);
			Q.push('+');
		}

		if (S.top() == in) {
			S.pop();
			Q.push('-');
		}
		else {
			printf("NO\n");
			return 0;
		}
	}

	while (Q.size()) {
		printf("%c\n", Q.front());
		
		Q.pop();
	}

	return 0;
}
