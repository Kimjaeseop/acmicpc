#include <iostream>
#include <string>

using namespace std;

int MAX;
string str;

int main(void)
{
	int temp = 0;

	freopen("input_1.txt", "r", stdin);

	for (int N = 0; N < 3; N++) {
		MAX = temp = 0;
		cin >> str;

		for (int i = 1; i < 8; i++) {
			if (str[i-1] == str[i]) 
				temp++;
			else 
				temp = 0;

			MAX = max(MAX, temp);
		}

		cout << MAX + 1 << endl;
	}

	return 0;
}


