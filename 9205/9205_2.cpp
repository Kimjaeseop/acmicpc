#include <cstdio>
#include <queue>
#include <utility>

using namespace std;

int t, n;
int curLocate, nextDistance;

typedef struct {
    short x, y;
} NODE;

NODE node[102];

queue<pair<NODE, int>> Q; // prev, distance

short abs(short N)
{
    return N > 0 ? N : -N; 
}

int main(void)
{
    freopen("input_1.txt", "r", stdin);
    scanf("%d", &t);

    while (t--) {
		int depth = 0;
        scanf("%d", &n);

		while (!Q.empty())
			Q.pop();

        for (int i = 0; i < n + 2; i++) {
            scanf("%hd %hd", &(node[i].x), &(node[i].y));
        }

        curLocate = abs(node[0].x-node[n].x) + abs(node[0].y-node[n].y);
        if (curLocate <= 20 * 50) {
            printf("happy\n");
            continue;
		}

		Q.push({node[0], 0});

		while (!Q.empty()) {
			int N = Q.size();
			depth++;

			while (N--) {
				pair<NODE, int> curNode = Q.front();
				Q.pop();

				curLocate = abs(curNode.first.x-node[depth].x) + abs(curNode.first.y-node[depth].y);
				nextDistance = curNode.second + curLocate;

				if (nextDistance <= 1000) {
					Q.push({node[depth], nextDistance});
				}

				Q.push({curNode.first, curNode.second});
			}

			if (depth == n + 1) {
				while (!Q.empty()) {
					if (Q.front().second <= 1000) {
						printf("happy\n");
						break;
					}
					Q.pop();
				}
				printf("end\n");
				break;
			}
		}
    }   
    return 0;
}
