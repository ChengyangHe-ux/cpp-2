#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    getline(cin,s);
    stack<int> T;
    for(int i=0;i<s.length();i++){
        if(s[i]=='(') T.push(i);
        else if(s[i]==')'){
            if(T.empty()){
                cout<<"rightmore"<<" "<<i<<endl;
                return 0;
            }else{
                T.pop();
            }
        }
    }
    if(T.empty()){
        cout<<"ok"<<endl;
        return 0;
    }
    cout<<"leftmore"<<" ";
    while(!T.empty()){
        cout<<T.top()<<" ";T.pop();
    }
    return 0;
}