#include<iostream>
using namespace std;
int main(){
    int ans =1;
    string s;
    
    cin>>s;
    for (int i=0;i<s.length();i++){
        if (s[i]==s[i+1]){
            ans++;
            if (ans==7){
                cout<<"YES"<<endl;
                return 0;
            }
        }
        else{
            ans=1;
        }
    }
    cout<<"NO"<<endl;
}   