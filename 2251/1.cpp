#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> V(100, vector<int>(100));
int X, Y;

int main(void)
{
	freopen("input_2.txt", "r", stdin);

	cin >> X >> Y;

	for (auto i : X) {
		for (auto j : Y) {
			cin >> V[i][j];
		}
	}

	for (auto i : X) {
		for (auto j : Y) {
			cout << V[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}
	
