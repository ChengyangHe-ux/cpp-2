#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
    cin>>n;
    vector<int> a(n);
    vector<int> b(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    for(int j=0;j<n;j++){
        cin>>b[j];
    }
    sort(b.begin(),b.end());
    long long m=0;
    int i=0,j=0;
    while(i<n&&j<n){
        if(a[i]<b[j]){
            i++;
        }else if(a[i]>b[j]){
            j++;
        }else{
            i++;
            j++;
            m++;
        }
    }
    cout<<n-m<<endl;
	return 0;
}
