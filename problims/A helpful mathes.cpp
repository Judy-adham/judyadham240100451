

#include<iostream>
#include<algorithm>
using namespace std;

int main() {
    string str;
    cin >> str;

    int size = str.size();
    int n = (size / 2) + 1;   
    int a[n];
    int count = 0;

    for(int i = 0; i < size; i += 2) {
        a[count] = str[i] - '0';
        count++;
    }

    sort(a, a + n);

    for(int i = 0; i < n; i++) {
        cout << a[i];
        if(i != n - 1) cout << "+";  
    }

    return 0;
}
