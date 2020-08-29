#include <stdio.h>
#include <utility>
#include <vector>

using namespace std;

/*
   review

   1. 사실 이미 다녀온 경로를 체크할 필요가 없었다.
   이미 다녀간 경로로 다시 돌아갈 수 있는 경우는 현재 함수를 호출한 노드밖에 없기 때문에
   함수 매개변수로 호출한 노드만 명시해두고 if 문으로 체크해주면 된다.

   2. 굳이 모든 점을 체크할 필요가 없다.
   시작노드, 끝노드가 pair 형태이기 때문에 같은 경로를 두번 체크한다는 것은 알고 있었지만
   그 문제가 아니고,

   그냥 임의의 점 하나를 잡고 가장 먼 점 두 노드를 찾아서
   그 두 노드간 길이를 구하면 된다.

   참조한 레퍼런스
   http://wookje.dance/2018/01/07/boj-1967-%ED%8A%B8%EB%A6%AC%EC%9D%98-%EC%A7%80%EB%A6%84/

*/ 

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
