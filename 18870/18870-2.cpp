#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> V1;
vector<int> V2;

int N;

// 출력형식 제대로 안봐서 시간초과
// 중복원소 제거 : resize가 erase보다 빠름
// lower_bound도 굳이 구현하는 것보다 STL 사용하는 것이 더 빠름

//int lower_bound(int n);

int main(void)
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int in;

	freopen("input_1.txt", "r", stdin);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> in;

		V1.push_back(in);
		V2.push_back(in);
	}

	// unique 실행 조건 -> 오름차순 정렬
	sort(V2.begin(), V2.end());
	V2.resize(unique(V2.begin(), V2.end()) - V2.begin());
	//V2.erase(unique(V2.begin(), V2.end()), V2.end());

	for (int i : V1) {
		cout << lower_bound(V2.begin(), V2.end(), i) - V2.begin() << " ";
	}

	return 0;
}

/*
int lower_bound(int n) {
	int start = 0, mid, end = V2_SIZE - 1;

	while (end > start) {
		mid = (start + end) / 2;

		if (V2[mid] >= n)
			end = mid;
		else
			start = mid + 1;
	}

	return end;
}
*/
