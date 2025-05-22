#include <bits/stdc++.h>
using namespace std;
struct Node{
    string s;
    int x;
};
bool cmp(Node &A,Node &B){
    return A.x>B.x;
}
int main(){
    int n;
    cin>>n;

    vector<Node>M(n);
    for(int i=0;i<n;i++){
        cin>>M[i].s>>M[i].x;
    }
    sort(M.begin(),M.end(),cmp);
    for(int i=0;i<n;i++){
        cout<<M[i].s<<" "<<M[i].x<<endl;
    }
    return 0;
}