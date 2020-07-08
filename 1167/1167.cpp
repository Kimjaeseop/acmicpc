#include <iostream>
#include <vector>
#include <utility>
#include <cstring>

using namespace std;

vector <vector <pair <int, int>>> V;
int N;
int IDX;
int A, B;
int MAX;
int ep; // end point
bool P[100001]; // check array를 전역으로 하면 함수 호출이 끝나도 체크가 풀리지 않는 것 때문에 고민이었다.
// 하지만 DFS 함수 한 번 순회 후 초기화하고 다시 DFS를 돌리는 방식이므로 체크가 풀리는 것이 상관 없어짐
void DFS (int s, int l)
{
    P[s] = 1;

    if (MAX < l) {
        ep = s;
        MAX = l;
    }

    int SIZE = V[s].size();

    for (int i=0; i<SIZE; i++) {
        if (P[V[s][i].first] == 0)
            DFS (V[s][i].first, l+V[s][i].second);
    }
}

int main (void) 
{
    freopen ("input.txt", "r", stdin);

    scanf("%d", &N);

    V.resize(N+1);

    for (int i=0; i<N; i++) {
        scanf("%d ", &IDX);

        while (1) {
            scanf("%d ", &A);

            if (A!=-1)
                scanf("%d ", &B);
            else
                break;

            //printf("%d %d\n", A, B);

            V[IDX].push_back(make_pair(A, B));
        }
    }

    DFS(1, 0); // 임의의 지점에서 DFS

    // Example
    //        R
    //   /    |    \
    //  0     2    3
    //  |
    //  1

    // 임의의 지점 아무곳에서나 시작하면 가장 긴 지름의 한쪽 vertex를 알 수 있다
    // 끝지점으로 다시 DFS를 돌리면 나머지 한 지점도 알 수 있다.
    // 양방향 트리이기 때문에 가능

    memset(P, 0, sizeof(P)); // 체크를 벡터에 하면 시간초과 // bool array에 하면 통과 ,,,,,,, // 1167-2에 이유있음
    MAX = 0;

    DFS(ep, 0);

    printf("%d\n", MAX);

    return 0;
}
