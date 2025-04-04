#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T--) {
        int n;
        cin>>n;

        vector<int> a(n);
        vector<int> diff(n);
        for (int i=0;i<n;i++) {
            cin>>a[i];
        }
        sort(a.begin(),a.end());

        int j=1;
        bool is=true;
        for (j=1;j<n;j++) {
            diff[j]=a[j]- a[j - 1];
            if (j>1&&diff[j]!=diff[j-1]) {
                is=false;
                break;
            }
        }
        if (!is) {
            int mm=a[n-1]-n;
            if (mm%2==0) {
                cout<<"Bob"<<endl;
            } else {
                cout<<"Alice"<<endl;
            }
        } else {
            cout<<"Bob"<<endl;
        }
    }
    return 0;
}
