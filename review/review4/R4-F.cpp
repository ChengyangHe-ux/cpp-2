#include <bits/stdc++.h>
using namespace std;

struct Node{
    string name;
    int score;
};
bool operator<(Node &a,Node &b){
    return a.score>b.score;
}
int main(){
    int n;
    cin>>n;
    vector<Node> T;
    for(int i=0;i<n;i++){
        string s;
        int c;
        cin>>s>>c;
        Node x;
        x.name=s;
        x.score=c;
        T.push_back(x);
    }
    sort(T.begin(),T.end());
    for(int i=0;i<n;i++){
        cout<<T[i].name<<" "<<T[i].score<<endl;
    }
    return 0;
}