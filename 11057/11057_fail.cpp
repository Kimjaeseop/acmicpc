#include <stdio.h>
#include <iostream>
#include <queue>

using namespace std;

// 큐 써서 메모리 초과

int main(void)
{
	int sum=0;
	int N;
	queue<int> q;

	scanf("%d", &N);

	if (N==1) {
		cout << "10" << endl;
		return 0;
	}

	for (int i=0; i<=9; i++)
		q.push(i);
	
	for (int i=0; i<N-1; i++) { // 길이만큼 큐에 넣고 빼고를 반복
		int size = q.size();
		while (size--) { // 큐에 있는 수보다 크거나 같은 수를 큐에 넣음
			for (int j=0; j<=9; j++)
				if (q.front() <= j)
					q.push(j);
			q.pop();
		}
	}

	printf("%ld\n", q.size());

	return 0;
}
