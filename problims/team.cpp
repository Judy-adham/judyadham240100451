#include<iostream>
using namespace std;
int main() {
	int n, o = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		int c = 0;
		if (x == 1) {
			c++;
			if (y == 1) {
				c++;
			}if (z == 1) {
				c++;

			}if (c >= 2) {
				o++;
			}
			cout << o << endl;
		}

	}
}