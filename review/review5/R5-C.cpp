#include <bits/stdc++.h>
using namespace std;

int main(){
    string s1;
    string s2;
    getline(cin,s1);
    getline(cin,s2);
    int n=s1.length();
    int m=s2.length();
    int count=0;
    for(int i=0;i<=n-m;i++){
        if(s1.substr(i,m)==s2){
            count++;
            i+=m-1;
        }
    }
    cout<<count<<endl;
    return 0;
}