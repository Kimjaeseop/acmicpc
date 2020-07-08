#include <iostream>
#include <stack>

using namespace std;

stack <int> S;
int K;
int in;
long long sum;

int main (void)
{
	cin >> K;

	for (int i=0; i<K; i++) {
		cin >> in;
		
		if (in)
			S.push(in);
		else
			S.pop();
	}

	for (int i=0; S.size(); i++) {
		sum += S.top();
		S.pop();
	}

	cout << sum << endl;

	return 0;
}
