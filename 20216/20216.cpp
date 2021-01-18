#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

int main(void)
{
	//freopen("input_2.txt", "r", stdin);
	string input;

	while (1) {
		getline(cin, input);
	
		if (input.back() == '?')
			cout << "Quack!" << endl << endl;
		else if (input.back() == '.')
			cout << "*Nod*" << endl << endl;
		else
			exit(0);
	}

	return 0;
}
