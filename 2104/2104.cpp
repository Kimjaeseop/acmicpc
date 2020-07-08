#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector <int> V;
long long sum;
long long MAX;
int N;
int in;

int main (void)
{
	freopen("input.txt", "r", stdin);

	cin >> N;

	for (int i=0; i<N; i++) {
		cin >> in;
		V.push_back(in);
	}

	for (int i=0; i<N; i++) {
		for (int j=i+1; j<N; j++) {

			for (int p=i; p<=j; p++)
				sum += V[p];

			sum *= *min_element(V.begin()+i, V.begin()+j+1);

			if (sum > MAX)
				MAX = sum;

			sum = 0;
		}
	}

	cout << MAX << endl;
		
	return 0;
}
