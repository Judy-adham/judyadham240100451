#include <iostream>     
using namespace std;
int main(){
    string v1,v2;
    cin>>v1>>v2;
    for(int i=0;i<v1.size();i++){
        if(v1[i]>=65 && v1[i]<=90){
            v1[i]=v1[i]+32;
        }
        if(v2[i]>=65 && v2[i]<=90){
            v2[i]=v2[i]+32;
        }
    }
    if(v1<v2){
        cout<<-1;
    }
    else if(v1>v2){
        cout<<1;
    }
    else{
        cout<<0;
    }
}