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

// ��Ʈ������ ���̿켱Ž������ leaf�� ã�� count
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
		// V[�θ�].push_back(�ڽ�);
		if (arr[i] == -1) 
			root = i;
		else 
			V[arr[i]].push_back(i);
	}

	cin >> del;

	// ���ͷ����ͷ� ���� ���� �θ��尣 edge�� ����
	for (vector<int>::iterator it = V[arr[del]].begin(); it != V[arr[del]].end(); it++) {
		// �ڽ��� DEL�̶�� edge�� ����
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




