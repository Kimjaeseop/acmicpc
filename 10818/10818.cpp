#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int in;
vector <int> V;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> in;

		V.push_back(in);
	}

	cout << *min_element(V.begin(), V.end()) << " " << *max_element(V.begin(), V.end())<< endl;

	return 0;
}

