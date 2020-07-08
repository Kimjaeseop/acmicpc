#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector <int> V[51];
int arr[51];
int N;
int root;
int del;
int ans;

// 루트노드부터 깊이우선탐색으로 leaf를 찾고 count
void DFS (int p) 
{
	if (V[p].size()==0)
		ans++;

	for (int i=0; i<V[p].size(); i++) {
		DFS(V[p][i]);
	}
}

int main(void)
{
	//freopen("input.txt", "r", stdin);

	cin >> N;

	for (int i=0; i<N; i++) {
		cin >> arr[i];
		// V[부모].push_back(자식);
		if (arr[i] == -1) 
			root = i;
		else 
			V[arr[i]].push_back(i);
	}

	cin >> del;

	// 이터레이터로 지울 노드와 부모노드간 edge를 지움
	for (vector<int>::iterator it = V[arr[del]].begin(); it != V[arr[del]].end(); it++) {
		// 자식이 DEL이라면 edge를 지움
		if (*it == del) {
			V[arr[del]].erase(it);
			break;
		}
	}

	if (del != root)
		DFS(root);

	cout << ans << endl;

	return 0;
}




