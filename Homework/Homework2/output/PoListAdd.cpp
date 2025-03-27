#include<bits/stdc++.h>
using namespace std;

class PolyList {
    int arr[1001];
public:
    PolyList(){
        for (int i=0;i<1001;i++) {
            arr[i]=0;
        }
    }
    void insert(int c, int e) {
        arr[e]+=c;
    }
    void add(const PolyList& other){
        for (int i=0;i<1001;++i) {
            arr[i]+=other.arr[i];
        }
    }
    void cout1(){
        bool first=true;
        for(int i=1000;i>=0;i--){
            if(arr[i]!=0){
                if(!first){
                    cout<<" ";
                }
                cout<<arr[i]<<" "<<i;
                first=false;
            }
        }
        cout<<endl;
    }
    friend istream& operator>>(istream &in,PolyList& a){
        int n;
        in>>n;
        for(int i=0;i<n;i++){
            int c,e;
            in>>c>>e;
            a.insert(c,e);
        }
        return in;
    }
};
int main() {
    PolyList Pa,Pb;
    cin>>Pa;
    cin>>Pb;
    Pa.add(Pb);
    Pa.cout1();
}
