#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#include <unistd.h>

using namespace std;

int arr[3];
queue<vector<int>> Q;
vector<vector<int>> chk;
vector<int> ans;

// 정답 체크 // 중복 원소를 체크한다
void ans_check()
{
	int tmp = Q.front()[2];

	for (auto iter = ans.begin(); iter != ans.end(); iter++) {
		if (*iter == tmp)
			return;
	}

	ans.push_back(tmp);
	return ;
}

// 남은 공간과 줄 수 있는 용량을 비교 한 뒤 벡터를 생성하고 이미 생성 되었던
// 벡터인지 비교해서 큐에 추가한다.
void func(int send, int recv, int remd)
{
	vector<int> T_1 = Q.front();
	vector<int> T_2(3);

	// 남은 공간 계산
	int tmp = arr[recv] - T_1[recv];

	if (!tmp)
		return ;
	
	// 남은 공간 > 줄 수 있는 용량
	if (tmp >= T_1[send]) {
		T_2[recv] = T_1[recv] + T_1[send];
		T_2[send] = 0;
	}
	// 남은 공간 < 줄 수 있는 용량
	else {
		T_2[recv] = T_1[recv] + tmp;
		T_2[send] = T_1[send] - tmp;
	}
	T_2[remd] = T_1[remd];

	for (auto iter = chk.begin(); iter != chk.end(); iter++) {
		if (*iter == T_2)
			return ;
	}

	Q.push(T_2);
	chk.push_back(T_2);
}

int main(void)
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen("input.txt", "r", stdin);

	cin >> arr[0] >> arr[1] >> arr[2];

	Q.push({0, 0, arr[2]});
	chk.push_back({0, 0, arr[2]});

	while (!Q.empty()) {
		if (Q.front()[0]) {
			func(0, 1, 2); func(0, 2, 1);
		}
		if (Q.front()[1]) {
			func(1, 0, 2); func(1, 2, 0);
		}
		if (Q.front()[2]) {
			func(2, 0, 1); func(2, 1, 0);
		}

		if (Q.front()[0] == 0) ans_check();

		Q.pop();
	}

	sort(ans.begin(), ans.end());

	/*
	for (auto iter = ans.begin(); iter != ans.end(); iter++)
		cout << *iter << " ";
		*/

	for (auto iter : ans) {
		cout << iter << " ";
	}

	cout << endl;

	return 0;
}
