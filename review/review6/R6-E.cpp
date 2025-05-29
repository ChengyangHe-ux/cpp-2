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
    void Output(){
        for(int i=0;i<n;i++){
            cout<<a[i]<<" ";
        }
        cout<<endl;
    }
    ~Array(){}
};
int main(){
    int n;
    cin>>n;
    int b[N];
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    Array M(n,b);
    int k;
    cin>>k;
    M.Output();
    M.Delete(k);
    M.Output();


    return 0;
}