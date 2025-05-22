#include <bits/stdc++.h>
using namespace std;

int main(){
    int na;
    cin>>na;
    vector<int>a(na);
    for(int i=0;i<na;i++){
        cin>>a[i];
    }

    int nb;
    cin>>nb;
    vector<int>b(nb);
    for(int i=0;i<nb;i++){
        cin>>b[i];
    }

    sort(a.begin(),a.end());
    sort(b.begin(),b.end());   

    vector<int>c;
    int i=0,j=0;
    while(i<na&&j<nb){
        if(a[i]==b[j]){
            i++;
            j++;
        }else if(a[i]>b[j]){
            j++;
        }else{
            c.push_back(a[i]);
            i++;
        }
    }
    while(i<na){
        c.push_back(a[i]);
        i++;
    }

    for(int k=0;k<c.size();k++){
        cout<<c[k]<<" ";
    }


    return 0;
}