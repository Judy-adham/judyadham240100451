#include<iostream>
using namespace std;
int main()
{
	int n, ans = 0;
	cin >> n;
	for (int i = 0; i <= n; i++) {
		string str;
		cin >> str;
		if (str == "++x" || str == "x++") {
			ans++;
		}
		else {
			ans--;
		}
		cout << ans;
	}



}