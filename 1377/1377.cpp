#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int CNT;
int ANS;
vector <pair <int, int>> V;

// 1 5 2 3 10
// 1 2 3 5 10
// 처음 움직이지 않은 수
// 결국 해당 수 이전에 있던 수들은 오른쪽으로 이동
// 즉, 정렬된 오른쪽으로 옮겨진 이외의 수들은 왼쪽으로 이동했다는 뜻
// 가장 많이 왼쪽으로 이동한 수를 찾으면 됨.

int main(void)
{
	freopen("input.txt", "r", stdin);

	scanf("%d", &N);
	V.resize(N);

	for (int i=0; i<N; i++) {
		scanf("%d", &V[i].first);
		V[i].second = i;
	}

	sort(V.begin(), V.end());

	for (int i=0; i<N; i++) 
		ANS = max(ANS, V[i].second - i);

	printf("%d\n", ANS+1);

	return 0;
}
