#include <vector>
#include <algorithm>
#include <utility>
#include <cstdio>

using namespace std;

// 정말 오랜시간 투자한 문제
// DP 냅색처럼 풀고 BFS로 풀면 시간초과, 메모리초과
// 방향을 잡았음에도 회의 종료 이후 바로 시작 할 수 있다는 것을 못봐서 시간 많이 날림

vector <pair<int, int>> V;
int N;

int cmp(pair<int, int> A, pair<int, int> B)
{
    if (A.second == B.second) {
        return A.first < B.first;
    }

    return A.second < B.second;
}

int main(void)
{
    //freopen("input.txt", "r", stdin);
    int ANS = 0;
    int LAST = 0;
	int A, B;

    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
		scanf("%d %d", &A, &B);
		V.push_back({A, B});
    }

    sort(V.begin(), V.end(), cmp);

    for (int i = 0; i < N; i++) {
        if (V[i].first >= LAST) {
            ANS++;
            LAST = V[i].second;
        }
    }

    printf("%d\n", ANS);

    return 0;
}
