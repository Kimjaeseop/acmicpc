#include <stdio.h>
#include <utility>
#include <vector>

using namespace std;

vector<pair<int, int>> V[10001];
int N, MAX;
int chk[10001];

void BFS(int num, int len)
{
    chk[num] = 1;

    if (V[num].size() == 1 && MAX < len)
        MAX = len;

    vector<pair<int, int>>::iterator it;

    for (it = V[num].begin(); it != V[num].end(); it++) {
        if (chk[it->first] == 0)
            BFS(it->first, len + it->second);
    }

    chk[num] = 0;
}

int main(void)
{
    //freopen("input1.txt", "r", stdin);

    int a, b, c;
    int pre_val;
    int ans, val;

    a = b = c = pre_val = ans = val = 0;

    scanf("%d", &N);

    for (int i = 0; i < (N-1); i++) {
        scanf("%d %d %d", &a, &b, &c);

        V[a].push_back(make_pair(b, c));
        V[b].push_back(make_pair(a, c));
    }

    for (int i = 1; i < (N - 1); i++) {
        if (V[i].size() == 1) {
            BFS(i, 0);
        }
    }

    printf("%d\n", MAX);

    return 0;
}

