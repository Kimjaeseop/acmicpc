#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

typedef struct {
	short x, y;
} NODE;

// 간단한 재귀로 풀려고도 해보고 BFS로 풀려고도 해봤는데
// 잘 풀리지 않아서 이것저것 참고했다,,,

// 사실은 정말 간단한 그래프 문제인데
// 접근 가능한 편의점을 그래프화 하는 부분을 생각지 못했다.

// 굳이 플로이드 와샬로 풀지 않아도 BFS, DFS로 접근 가능

// 편의점을 모두 들리지 않아도 된다는 사실을 인지하지 못해서 뻘짓을 많이했다

// DFS로 접근 가능한 편의점들로 나아가면서 최종점에 도달하면 happy
// 즉, visited[n + 1] == true 인데 또하나 배웠다.

// 클린코드를 작성하는 방법 중 함수명은 동사로 네이밍을해서 직관적으로 보여야한다는 말을 듣고
// 적용해 보았다.

int t, n;

vector<int> v[102];
vector<bool> visited(102, false);

void DFS(int curLocate)
{
	visited[curLocate] = true;

	for (int i = 0; i < v[curLocate].size(); i++) {
		if (visited[v[curLocate][i]] == false) {
			DFS(v[curLocate][i]);
		}
	}
}

bool getDistance(NODE prev, NODE next)
{
	return abs(prev.x - next.x) + abs(prev.y - next.y) > 1000 ? false : true;
}

int main(void)
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//freopen("input_1.txt", "r", stdin);

	cin >> t;

	while (t--) {
		vector<NODE> locate;
		cin >> n;

		for (int i = 0; i < 102; i++) {
			v[i].clear(); 
		}

		visited = vector<bool>(102, false);

		short in_x, in_y;
		for (int i = 0; i < n + 2; i++) {
			cin >> in_x >> in_y;
			locate.push_back({in_x, in_y});
		}

		for (int i = 0; i < n + 2; i++) {
			for (int j = i + 1; j < n + 2; j++) {
				if (getDistance(locate[i], locate[j]) == true) {
					v[i].push_back(j);
					v[j].push_back(i);
				}
			}
		}

		DFS(0);

		cout << (visited[n + 1] == true ? "happy" : "sad") << "\n";
	}

	return 0;
}
