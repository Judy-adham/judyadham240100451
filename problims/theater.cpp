//4 theater
#include<iostream>
using namespace std;
int main() {

	long long n, m, a, s, o;
	cin >> n >> m >> a;
	if (n % a == 0)
		s = n / a;
	else
		s = (n / a) + 1;
	if (m % a == 0)
		o = m / a;
	else
		o = (m / a) + 1;
	cout << s * o;



}