#include<iostream>
using namespace std;
class SortList{
public:
    int arr[200];
    int size;
    SortList():size(0){}
    void init(int a[],int n){
        for(int i=0;i<n;i++){
            arr[i]=a[i];
        }
        size=n;
    }
    void merge(SortList &other,SortList &result){
        int i=0,j=0,k=0;
        while(i<size && j<other.size){
            if(arr[i]<other.arr[j])
                result.arr[k++]=arr[i++];
            else if(arr[i]>other.arr[j])
                result.arr[k++]=other.arr[j++];
            else{
                result.arr[k++]=arr[i];
                i++;j++;
            }
        }
        while(i<size) result.arr[k++]=arr[i++];
        while(j<other.size) result.arr[k++]=other.arr[j++];
        result.size=k;
    }
};
int main(){
    int na;
    cin>>na;
    int a[200];
    for(int i=0;i<na;i++){
        cin>>a[i];
    }
    SortList A;
    A.init(a,na);
    int nb;
    cin>>nb;
    int b[200];
    for(int i=0;i<nb;i++){
        cin>>b[i];
    }
    SortList B;
    B.init(b,nb);
    SortList C;
    A.merge(B,C);
    for(int i=0;i<C.size;i++){
        if(i!=0)
            cout<<" ";
        cout<<C.arr[i];
    }
    return 0;
}