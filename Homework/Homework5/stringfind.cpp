#include <iostream>
#include <string>
using namespace std;

int main() {
    string s,t1,t2;
    getline(cin,s);
    getline(cin,t1);
    getline(cin,t2);
    int n=s.size(),m=t1.size();
    string ans;
    for (int i=0;i<=n-m;){
        if(i+m<=n&&s.substr(i,m)==t1){
            ans+=t2;
            i+=m;
        }else{
            ans+=s[i];
            i++;
        }
    }
    ans+=s.substr(n-m+1);
    cout<<ans<<endl;
    return 0;
}
