#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    int count=0;
    for(int i=0;i<s.length();i++){
        for(int j=i+1;j<=s.length();j++){
            string ss=s;
            reverse(ss.begin()+i,ss.begin()+j);
            if(ss<s){
                count++;
            }
        }
    }
    cout<<count<<endl;
    return 0;
}