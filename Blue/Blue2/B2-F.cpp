#include <bits/stdc++.h>
using namespace std;
vector<int> myadd(vector<int>a,vector<int>b){
    if(a.size()<b.size()) swap(a,b);
    int mini=min(a.size(),b.size());
    for(int i=0;i<mini;i++){
        a[i]+=b[i];
        if(a[i]>=10){
            a[i]-=10;
            a[i+1]+=1;
        }
    }
    return a;
}
vector<int> mysub(vector<int>a,vector<int>b){
    for(int i=0;i<b.size();i++){
        if(a[i]-b[i]>=0){
            a[i]-=b[i];
        }else{
            a[i]=a[i]+10-b[i];
            a[i+1]-=1;
        }
    }
    for(int i=b.size();i<a.size();i++){
        if(a[i]<0){
            a[i+1]--;
            a[i]+=10;
        }
    }
    while(a.size()>1&&a.back()==0){
        a.pop_back();
    }
    return a;
}
vector<int> mymul(vector<int>a,vector<int>b){
    vector<int> result(a.size()+b.size(),0);
    for(int i=0;i<a.size();i++){
        for(int j=0;j<b.size();j++){
            result[i+j]+=a[i]*b[j];
            if(result[i+j]>=10){
                result[i+j+1]+=result[i+j]/10;
                result[i+j]%=10;
            }
        }
    }
    while(result.size()>1&&result.back()==0) {
        result.pop_back();
    }
    return result;
}
int main(){
    string s1;
    string s2;
    cin>>s1>>s2;
    vector<int>a;
    vector<int>b;
    for(int i=s1.length()-1;i>=0;i--){
        a.push_back(s1[i]-'0');
    }
    for(int i=s2.length()-1;i>=0;i--){
        b.push_back(s2[i]-'0');
    }
    vector<int>c=myadd(a,b);
    vector<int>d=mysub(a,b);
    vector<int>ans=mymul(c,d);
    for(int i=ans.size()-1;i>=0;i--){
        cout<<ans[i];
    }
    
    return 0;
}