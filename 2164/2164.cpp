#include <iostream>
#include <deque>

using namespace std;

int N;
deque <int> dq;

int main(void)
{
	scanf("%d", &N);

	for (int i=1; i<=N; i++) {
		dq.push_back(i);
	}

	for (int i=0; i<N-1; i++) {
		dq.pop_front();
		dq.push_back(dq.front());
		dq.pop_front();
	}

	printf("%d\n", dq.front());
	return 0;
}
