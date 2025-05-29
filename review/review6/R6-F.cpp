#include <bits/stdc++.h>
using namespace std;
#define N 100
class Array{
    int a[N],n;
public:
    Array(int n,int b[]):n(n){
        for(int i=0;i<n;i++){
            a[i]=b[i];
        }
    }
    void Delete(int k){
        int i=0;
        for(i=k;i<n-1;i++){
            a[i]=a[i+1];
        }
        n--;
    }
    void Insert(int x){
        int i=0;
        n++;
        for(i=n-2;i>=0;i--){
            if(a[i]>x){
                a[i+1]=a[i];
            }else{
                break;
            }
        }
        a[i+1]=x;
    }
    void Output(){
        for(int i=0;i<n;i++){
            cout<<a[i]<<" ";
        }
        cout<<endl;
    }
    ~Array(){}
};
int main(){
    int n;cin>>n;
    int b[N];
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    int x;
    cin>>x;
    Array M(n,b);
    M.Output();
    M.Insert(x);
    M.Output();

    return 0;
}