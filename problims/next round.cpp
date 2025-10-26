
#include <iostream>
using namespace std;

int main()

{
    int n, k, a[50],count=0;
    cin >> n >>k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        if (a[i] >= a[k]&&a[k]!=0) {
            count++;

        }
    }cout << count;
}

