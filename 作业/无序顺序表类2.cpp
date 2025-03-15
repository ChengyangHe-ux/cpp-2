#include<iostream>
using namespace std;
class SeqList{
public:
    int arr[200];
    int size;
    SeqList(){size=0;}
    void init(int a[],int n){
        for(int i=0;i<n;i++){
            arr[size++]=a[i];
        }
    }
    bool contains(int x){
        for(int i=0;i<size;i++){
            if(arr[i]==x)return true;
        }
        return false;
    }
};
int main(){
    int na;cin>>na;
    int a[200];
    for(int i=0;i<na;i++){
        cin>>a[i];
    }
    SeqList A;
    A.init(a,na);
    int nb;cin>>nb;
    int b[200];
    for(int i=0;i<nb;i++){
        cin>>b[i];
    }
    SeqList B;
    B.init(b,nb);
    int inter[200],interS=0;
    for(int i=0;i<A.size;i++){
        int x=A.arr[i];
        if(B.contains(x)){
            bool d=false;
            for(int j=0;j<interS;j++){
                if(inter[j]==x){d=true;
                    break;
                }
            }
            if(!d) inter[interS++]=x;
        }
    }
    for(int i=0;i<interS;i++){
        cout<<inter[i];
        if(i!=interS-1)
            cout<<" ";
    }
    return 0;
}