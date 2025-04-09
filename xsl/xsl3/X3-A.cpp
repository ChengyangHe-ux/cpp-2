#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    int sum=0;
    int count=1;
    for(int i=0;i<s.length()-1;i++){
        if(s[i]=='w'){
            if(s[i+1]=='a'){
                sum++;
            }
        }
        if(s[i]=='W'){
            if(s[i+1]=='a'){
                sum+=3;
            }
            if(s[i+1]=='A'){
                sum+=5*count;
                count++;
            }
        }
    }
    cout<<sum<<endl;
    return 0;
}