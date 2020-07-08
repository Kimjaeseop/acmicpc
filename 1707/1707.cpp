#include <iostream>
#include <vector>

using namespace std;

// 원리는 알겠는데 코드 짜는 테크닉이 부족해서 검색해서 풀었음 (거의 copy)
// 이분 그래프

int T, V, E;
int A, B;

int ANS;

vector <int> vec[20001];
int check[20001];

bool BFS(int N, int flag)
{
    check[N] = flag;

    int S = vec[N].size();

    for (int i = 0; i < S; i++) {
        int next = vec[N][i];

        if (check[next] == 0) { // *** 배우자 *** //
            if (BFS(next, -flag) == false) {
                return false;
            }
        }
        else if (check[N] == check[next]) {
            return false;
        }
    }

    return true;
}

int main(void)
{
    //freopen("input.txt", "r", stdin);

    scanf("%d", &T);

    while (T--) {
        scanf("%d %d", &V, &E);

        ANS = 0;

        for (int i = 1; i <= V; i++) {
            vec[i].clear();
            check[i] = 0;
        }

        for (int i = 0; i < E; i++) {
            scanf("%d %d", &A, &B);

            vec[A].push_back(B);
            vec[B].push_back(A);
        }

        for (int i = 1; i <= V; i++) {
            if (check[i] == 0) {
                if (BFS(i, 1) == 0) {
                    ANS = 1;
                    break;
                }
            }
        }

        printf("%s\n", ANS == 1 ? "NO" : "YES");
    }

    return 0;
}
