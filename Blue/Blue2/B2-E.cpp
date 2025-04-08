#include <bits/stdc++.h>
using namespace std;

bool check(int x){
    vector<int>ans;
    int count=0;
    while(x!=0){
        int xx=x%10;
        ans.push_back(xx);
        x/=10;
        count++;
    }
    if(count%2==1){
        return false;
    }
    int sum1=0,sum2=0;
    for(int i=0;i<count/2;i++){
        sum1+=ans[i];
    }
    for(int i=count/2;i<count;i++){
        sum2+=ans[i];
    }
    if(sum1==sum2)return true;
    return false;
    
}
int main(){
    int ans=0;
    for(int i=1;i<=100000000;i++){
        if(check(i)){
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}