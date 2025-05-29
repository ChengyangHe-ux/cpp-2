#include <bits/stdc++.h>
using namespace std;

struct PolyListNode{
    int c;//系数
    int e;//指数
};

class PolyList{
    vector<PolyListNode> T;
    int n;
public:
    PolyList(int n,int b[]):n(n){
        T.resize(n);
        for(int i=0,j=0;i<2*n-1;i+=2,j++){
            T[j].c=b[i];
            T[j].e=b[i+1];
        }
    }
    int solve(int x){
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=(T[i].c*pow(x,T[i].e));
        }
        return sum;
    }
    ~PolyList(){}
};
int main(){
    int n;
    cin>>n;
    int b[100];
    for(int i=0;i<2*n;i++){
        cin>>b[i];
    }
    PolyList M(n,b);
    int d;
    cin>>d;
    int ans=M.solve(d);
    cout<<ans<<endl;
    return 0;
}