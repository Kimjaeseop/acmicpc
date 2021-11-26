#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

int N, M;
bool visit[52][52];
vector<vector<int>> V(51);
queue<int> Q;

int DFS(int startPoint)
{
	int countChangeState = 0;

	for (int i = 1; i <= N; i++) {
		if (visit[startPoint][i] == true && visit[i][0] == false) {
			visit[startPoint][i] = visit[i][startPoint] = visit[i][0] = true;
			countChangeState += DFS(i);
		}
	}

	return countChangeState;
}

int main(void)
{
	int knowPeopleNum, knowPeopleIdx, peopleNum, peopleIdx, countChangeState, ANS;
	bool findKnowPeople;

	knowPeopleNum = knowPeopleIdx = peopleNum = peopleIdx = countChangeState = findKnowPeople = ANS = 0;

	freopen("input_7.txt", "r", stdin);

	scanf("%d %d", &N, &M);
	scanf("%d", &knowPeopleNum);

	for (int i = 0; i < knowPeopleNum; i++) {
		scanf("%d", &knowPeopleIdx);

		visit[knowPeopleIdx][0] = true;
		Q.push(knowPeopleIdx);
	}

	for (int i = 0; i < M; i++) {
		scanf("%d", &peopleNum);

		for (int j = 0; j < peopleNum; j++) {
			scanf("%d", &peopleIdx);

			V[i].push_back(peopleIdx);
		}
	}

	for (int i = 0; i < M; i++) {
		for (vector<int>::iterator iter_1 = V[i].begin(); iter_1 != V[i].end(); iter_1++) {
			for (vector<int>::iterator iter_2 = iter_1+1; iter_2 != V[i].end(); iter_2++) {
				visit[*iter_1][*iter_2] = visit[*iter_2][*iter_1] = true;
			}
		}
	}

	if (knowPeopleNum == 0) {
		printf("%d\n", M);

		return 0;
	}

	for (int i = 1; i <= N; i++) {
		countChangeState = 0;

		for (int j = 1; j <= N; j++) {
			if (visit[j][0] == true) {
				countChangeState += DFS(j);
			}
		}

		if (countChangeState == 0) {
			break;
		}
	}

	/*
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= N; j++) {
			printf("%d ", visit[i][j]);
		}
		printf("\n");
	}
	*/

	for (int i = 0; i < M; i++) {
		findKnowPeople = 0;

		for (vector<int>::iterator iter = V[i].begin(); iter != V[i].end(); iter++) {
			if (visit[*iter][0] == true) {
				findKnowPeople = 1;
				break;
			}
		}

		if (findKnowPeople == false) {
			ANS++;
		}
	}

	printf("%d\n", ANS);

	return 0;
}
