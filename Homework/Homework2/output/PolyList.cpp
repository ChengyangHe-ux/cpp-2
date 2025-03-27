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
    int evaluate(int x) {
        int result=0;
        for (int i=0;i<1001;i++) {
            if (arr[i]!=0) {
                result+=arr[i]*pow(x, i);
            }
        }
        return result;
    }
};
int main() {
    int n;
    cin>>n;
    PolyList P;
    for (int i=0;i<n;i++) {
        int c,e;
        cin>>c>>e;
        P.insert(c, e);
    }
    int x;
    cin>>x;
    cout<<P.evaluate(x)<<endl;
    return 0;
}
