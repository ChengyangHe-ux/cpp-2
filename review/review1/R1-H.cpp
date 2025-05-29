#include <bits/stdc++.h>
using namespace std;
#define N 100
class SeqList{
    int n,a[N];
public:
    SeqList(){n=0;}
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
    void inter(SeqList &B){
        for(int i=0;i<n;i++){
            for(int j=0;j<B.n;j++){
                if(a[i]==B.a[j]) cout<<a[i]<<" ";
            }
        }
    }
    void sortedinter(SeqList &B){
        SeqList C;
        int i=0;int j=0;
        C.n=0;
        while(i<n&&j<B.n){
            if(a[i]<B.a[j]){
                C.a[C.n++]=a[i++];
            }else if(a[i]==B.a[j]){
                C.a[C.n++]=a[i++];
                j++;
            }else C.a[C.n++]=B.a[j++];
        }
        while(i<n){
            C.a[C.n++]=a[i++];
        }
        while(j<B.n){
            C.a[C.n++]=B.a[j++];
        }
        C.Output();
    }
    void Output(){
        for(int i=0;i<n;i++) cout<<a[i]<<" ";
        cout<<endl;
        cout<<endl;
    }
};  
int main(){ 
    int n;
    cin>>n;
    int b[N];
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    SeqList M(n,b);
    int m;
    cin>>m;
    int c[N];
    for(int i=0;i<m;i++){
        cin>>c[i];
    }
    SeqList D(m,c);
    M.sortedinter(D);

    return 0;
}