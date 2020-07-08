#include <iostream>
#include <vector>
#include <utility>

using namespace std;

vector <vector <pair <int, int>>> V;
int N;
int IDX;
int A, B;
int MAX;
int ep; // end point

void DFS (int s, int l, vector <int> &P) // 포인터를 넘겨주는 방식이 아니면 매번 벡터의 복사가 발생되어 시간초과
{
    P[s] = 1;

    if (MAX < l) {
        ep = s;
        MAX = l;
    }   

    int SIZE = V[s].size();

    for (int i=0; i<SIZE; i++) {
        if (P[V[s][i].first] == 0)
            DFS (V[s][i].first, l+V[s][i].second, P); 
    }   
}

int main (void) {
    //freopen ("input2.txt", "r", stdin);
    
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


    vector <int> P (N+1);
    DFS(1, 0, P); 

    vector <int> T (N+1);
    MAX = 0;
    DFS(ep, 0, T); 

    printf("%d\n", MAX);

    return 0;
}

