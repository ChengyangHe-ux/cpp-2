#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;

    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int maxi=arr[n-1];
    int count=0;
    
    for(int i=n-1;i>=0;i--){
        if(arr[i]==maxi) 
            count++;
        else 
            break;
    }
    int r=n-count;
    bool win;
    
    if(r==0){
        win=(count%2==1);
    } else {        
        win=((count%2==1)||(r%2==1));
    }
    cout <<(win?"YES":"NO")<<endl;
    return 0;
}