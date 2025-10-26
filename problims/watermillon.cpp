#include <iostream>
using namespace std;

int main() {
	int w;
	cin >> w;
	if (w % 2 == 0 && w != 0) {
		cout << "yes";
	}

	else {
		cout << "no";
		return 0;
	}
}
