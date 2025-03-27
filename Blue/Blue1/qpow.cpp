#include <bits/stdc++.h>
using namespace std;
int qpow(int a,int n,int mod){
    if(n==0){
        return 1;
    }
    else if(n%2==1){
        return ((1ll*qpow(a,n-1,mod)%mod);
    }
    else {
        int tmp=qpow(a,n/2,mod);
        return (1ll*tmp*tmp);
    }
}
