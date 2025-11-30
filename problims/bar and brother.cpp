#include<iostream>
using namespace std;
int main(){
    int fw,sw ,count=0;
    cin>>fw>>sw;
    while(fw<=sw){
        fw=fw*3;
        sw=sw*2;
        count++;
    }
    cout << count;
}