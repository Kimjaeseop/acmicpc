#include <iostream>
#include <string>

int MAX, cnt;

using namespace std;

int main(void)
{
	//freopen("input_1.txt", "r", stdin);

	string str;

	for (int i = 0; i < 3; i++) {
		cin >> str;
		cnt = MAX = 0;

		for (int j = 1; j < 8; j++) {
			if (str[j-1] == str[j]) 
				cnt++;
			else 
				cnt = 0;

			MAX = max(cnt, MAX);
		}

		cout << MAX + 1 << endl;
	}

	return 0;
}
