#include <bits/stdc++.h>
using namespace std;
#define N 100
class SeqList{
    int n,a[N];
public:
    SeqList(int n,int b[]):n(n){
        for(int i=0;i<n;i++){
            a[i]=b[i];
        }
    }
    
    void Insert(int x){
        a[n++]=x;
    }
    
    int Find(int x){
        for(int i=0;i<n;i++){
            if(a[i]==x)return i;
        }
        return -1;
    } 
    
    void Delete(int index){
        for(int i=index;i<n-1;i++){
            a[i]=a[i+1];
        }
        n--;
    }

    void solve(int x){
        int j=Find(-x);
        if(j!=-1){Delete(j);}
        else if(x<0){}
        else{Insert(x);}
    }
    void Output(){
        for(int i=0;i<n;i++) cout<<a[i]<<" ";
        cout<<endl;
    }
};  
int main(){ 
    int n;cin>>n;
    int b[N];
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    SeqList M(n,b);
    int m;cin>>m;
    for(int i=0;i<m;i++){
        int x;
        cin>>x;
        M.solve(x);
    }
    M.Output();
    return 0;
}