#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vector<set<int>> S(n);
    for(int i=0;i<n;i++){
        for(int j=0;j<a[i];j++){
            int x;
            cin>>x;
            S[i].insert(x);
        }
    }
    char op;
    int m;
    cin>>op>>m;
    vector<int> idx(m);
    for(int i=0;i<m;i++){
        cin>>idx[i];
    }
    set<int> res;
    if(m==0){
        if(op=='D'){
            for(int i=0;i<=30;i++){
                res.insert(i);
            }
        }
    }else{
        if(op=='A'){
            res=S[idx[0]];
            for(int i=1;i<m;i++){
                set<int>tmp;
                set_intersection(res.begin(), res.end(),S[idx[i]].begin(), S[idx[i]].end(),inserter(tmp, tmp.begin()));
                res.swap(tmp);
            }
        }else if(op=='B'){
            for(int i=0;i<m;i++){
                for(auto it=S[idx[i]].begin();it!=S[idx[i]].end();it++){
                    res.insert(*it);
                }
            }
        }
        else if(op=='C'){
            res=S[idx[0]];
            for(int i=1;i<m;i++){
                set<int> tmp;
                set_symmetric_difference(res.begin(), res.end(),S[idx[i]].begin(), S[idx[i]].end(),inserter(tmp, tmp.begin()));
                res.swap(tmp);
            }
        }
        else if(op=='D'){
            set<int> uni;
            for(int i=0;i<m;i++){
                for(auto it=S[idx[i]].begin();it!=S[idx[i]].end();it++){
                    uni.insert(*it);
                }
            }
            for(int i=0;i<=30;i++){
                if(!uni.count(i)){
                    res.insert(i);
                }
            }
        }
        else if(op=='E'){
            set<int> uni;
            for(int i=0;i<m;i++){
                for(auto it=S[idx[i]].begin();it!=S[idx[i]].end();it++){
                    uni.insert(*it);
                }
            }
            if(!uni.empty()){
                int gmin=*uni.begin();
                for(int i=0;i<m;i++){
                    for(auto it=S[idx[i]].begin();it!=S[idx[i]].end();it++){
                        if(*it!=gmin){
                            res.insert(*it);
                        }
                    }
                }
            }
        }
    }
    long long ma=0;
    for(auto it=res.begin();it!=res.end();it++){
        long long bit=(1LL<<*it);
        ma+=bit;
    }
    cout<<ma<<endl;
    return 0;
}