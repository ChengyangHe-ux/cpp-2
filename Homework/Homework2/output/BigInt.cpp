#include <bits/stdc++.h>
using namespace std;
class BigInt{
    vector<int> digits;
public:
    BigInt(int x=0){
        if(x==0){
            digits.push_back(0);
        }
        while(x>0){
            digits.push_back(x%10);
            x/=10;
        }
    }
    void mul(int num){
        int carry=0;
        for(int i=0;i<digits.size();i++){
            int product=digits[i]*num+carry;
            digits[i]=product%10;
            carry=product/10;
        }
        while(carry>0){
            digits.push_back(carry%10);
            carry/=10;
        }
    }
    BigInt operator*(const BigInt &other){
        BigInt result;
        int newSize=digits.size()+other.digits.size();
        result.digits.resize(newSize);
        for (int i=0;i<newSize;i++) {
            result.digits[i]=0;
        }
        for (int i=0;i<digits.size();i++){
            for (int j=0;j<other.digits.size();j++) {
                result.digits[i+j]+=digits[i]*other.digits[j];
            }
        }
    for (int i=0;i<result.digits.size();i++) {
        if (result.digits[i]>=10) {
            if (i+1==result.digits.size()) {
                result.digits.push_back(0);
            }
            result.digits[i+1]+=result.digits[i]/10;
            result.digits[i]%=10;
        }
    }
    while (result.digits.size()>1&&result.digits.back()==0)
        result.digits.pop_back();
    return result;
    }
    BigInt pow(int k) const {
        BigInt base=*this;
        BigInt result(1);
        while (k>0) {
            if (k%2==1) {
                result=result*base;
            }
            base=base*base;
            k/=2;
        }
        return result;
    }
    void cout1() const {
        for (int i=digits.size()-1;i>=0;i--)
            cout<<digits[i];
        cout<<endl;
    }
};
int main(){
    int x,k;
    cin>>x>>k;
    BigInt a(x);
    BigInt result=a.pow(k);
    result.cout1();
    return 0;
}