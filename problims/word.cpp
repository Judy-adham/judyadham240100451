# include <iostream>
# include <string>
using namespace std;
int main(){
    string name;
    cin>>name;
    int sm=0,ca=0;
    for(int i=0;i<name.length();i++){
        if(name[i]>='a' && name[i]<='z'){

            sm++;
        }
        else{
        
            ca++;
        }
    }
    char res;
    if (ca>sm){
        for(int i=0;i<name.length();i++){
            res=toupper(name[i]);
            cout<<res;
        }
    }
    else{
        for(int i=0;i<name.length();i++){
            name[i]=tolower(name[i]);
        }
    }
    cout<<name<<endl;
}