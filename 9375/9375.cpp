#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>
#include <map>

using namespace std;

int t, n, ans, map_size, q_size, depth;
string in_1, in_2;

int getFactorial(int n)
{
	int num = 1;

	while (n)
		num *= n--;

	return num;
}

int getCombination(int n, int k)
{
	return getFactorial(n) / (getFactorial(k) * (getFactorial(n - k)));
}


int getPermutation(int n, int r)
{
	return  getFactorial(n) / n == r ? 1 : (getFactorial(n - r));
}

int main(void)
{
	freopen("input_1.txt", "r", stdin);

	cout << (getPermutation(2, 1) + getPermutation(1, 1)) + 3 << endl;

	cin >> t;

	while (t--) {
		map<string, int> m;
		queue<pair<int, int>> Q; // weight, check array
		vector<int> v;
		
		cin >> n;

		depth = ans = 0;

		for (int i = 0; i < n; i++) {
			cin >> in_1 >> in_2;
			m[in_2]++;
		}
		
		for (auto i = m.begin(); i != m.end(); ++i) {
			for (auto j = next(i); j != m.end(); ++j) {
				i->second > j->second ?
					v.push_back(getPermutation(i->second, j->second)) :
					v.push_back(getPermutation(j->second, i->second));
			}
		}

		map_size = m.size();
		for (int i = 0; i < map_size; i++) {
			Q.push({v[i], 1 << i});
		}

		while (!Q.empty()) {
			depth++;

			q_size = Q.size();
			while (q_size--) {
				pair<int, int> node = Q.front();
				Q.pop();

				ans += node.first;
				cout << ans << endl;
				
				for (int i = 0; i < n; i++) {
					cout << "bit : " << (node.second & 1 << i) << endl;
					if (!(node.second & 1 << i)) {
						cout << "node.first : " << node.first << ", v[i] : " << v[i] << endl;
						Q.push({node.first*v[i], node.second | 1 << i});
					}
				}
			}
		}
		cout << "ans : " << ans << "\n";
	}

	return 0;
}
