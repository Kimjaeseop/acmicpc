#include <iostream>
#include <stack>
#include <string>
#include <ctype.h>

using namespace std;

stack<char> S;
string str;
int i;

int main(void)
{
	//freopen("input.txt", "r", stdin);

	while (1) {
		getline(cin, str);
		while (!(S.empty())) S.pop();

		//cout << str << endl;

		if (str.size() == 1 && str[0] == '.')
			return 0;

		for (i = 0; str[i] != '.'; i++) {
			if (str[i] == '(' || str[i] == '[') {
				S.push((char)str[i]);
			}
			else if (isalpha(str[i]) || isspace(str[i])) {
				continue;
			}
			else if (S.empty()) {
				break;
			}
			else if (str[i] == ')' && S.top() == '(') {
				S.pop();
			}
			else if (str[i] == ']' && S.top() == '[') {
				S.pop();
			}
			else {
				break;
			}
		}
		if (str[i] == '.' && (S.size() == 0))
			printf("yes\n");
		else
			printf("no\n");
	}

	return 0;
}
