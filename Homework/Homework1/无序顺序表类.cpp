#include <iostream>
using namespace std;
class SeqList {
public:
    int arr[200];
    int size;
    SeqList(int n) {size=n;}
    void init(int* a, int n){
        for(int i=0;i<n;i++){
            arr[i]=a[i];
        }
    }
    void insert(int x) {
        arr[size++]=x;
    }
    void remove(int x) {
        int j=0;
        for(int i=0;i<size;i++){
            if(arr[i]!=x){
                arr[j++]=arr[i];
            }
        }
        size=j;
    }
    void print() {
        for(int i=0;i<size;i++){
            cout<<arr[i];
            if(i<size-1) cout << " ";
        }
    }
};
int main(){
    int n;
    cin>>n;
    int a[100];
    for(int i=0; i<n;i++){
        cin>>a[i];
    }
    SeqList list(n);
    list.init(a,n);
    int m;
    cin>>m;
    for(int i=0;i<m;i++){
        int t;
        cin>>t;
        if(t>0){
            list.insert(t);
        } else if(t<0){
            list.remove(-t);
        }
    }
    list.print();
    return 0;
}