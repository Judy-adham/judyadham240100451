#include<iostream>
using namespace std;
int main(){
    string name;
    cin>>name;
    int count=0;
    int flag=1;

    for(int i=0;i<name.size();i++){
        for(int j=i+1;j<name.size();j++){
            if(name[i]==name[j]){
                flag=0;
                break;
            }
               
            }
            if(flag){
                count++;

            }
            flag=1;
              
            }
        
    if(count%2==0){
        cout<<"CHAT WITH HER!";
    }else{
        cout<<"IGNORE HIM!";
    }
}