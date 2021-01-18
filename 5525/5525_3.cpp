#include <iostream>
#include <vector>
#include <string>

using namespace std;

string P = "I";
string S;
int N, M;

// 단순 string으로 비교 작업 -> 시간초과
// bitmap 처리 후 비교작업 -> 시간초과
// string, kmp algorithm -> 정답, 16ms
// O(N+M)

// https://baeharam.github.io/posts/algorithm/kmp/
// https://bowbowbow.tistory.com/6

vector<int> getPi(string p)
{
	int m = (int)p.size(), j = 0;

	vector<int> pi(m, 0);
	for (int i = 1; i < m; i++) {
		while (j > 0 && p[i] != p[j])
			j = pi[j - 1];
		if (p[i] == p[j])
			pi[i] = ++j;
	}

	return pi;
}

vector<int> kmp(string s, string p) // text, pattern
{
	vector<int> ans;
	vector<int> pi = getPi(p);

	int n = M, m = (int)p.size(), j = 0;

	for (int i = 0; i < n; i++) {
		while (j > 0 && s[i] != p[j])
			j = pi[j-1];
		if (s[i] == p[j]) {
			if (j == m-1) {
				ans.push_back(i-m+1);
				j = pi[j];
			}
			else {
				j++;
			}
		}
	}

	return ans;
}

int main(void)
{
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);

	freopen("input.txt", "r", stdin);

	cin >> N >> M;
	cin >> S;

	for (int i = 0; i < N; i++) {
		P += "OI";
	}

	cout << kmp(S, P).size() << endl;

	/*
	for (auto i : matched)
		cout << i+1 << endl;
	*/

	return 0;
}
