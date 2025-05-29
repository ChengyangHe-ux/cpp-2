#include <bits/stdc++.h>
using namespace std;

class BigInt{
    int *p;
    int size;//数组总容量
    int n;//实际使用的数字位数
    void Copy(const BigInt &obj){
        n=obj.n;
        size=obj.size;
        p=new int[size];
        for(int i=0;i<n;i++){
            p[i]=obj.p[i];
        }
    }
public:
    BigInt(int x=0){
        size=100;
        p=new int[size];
        if(x==0){
            n=1;p[0]=0;
            return;
        }
        n=0;
        while(x>0){
            p[n++]=x%10;
            x=x/10;
        }
    }
    BigInt(char s[]){
        n=strlen(s);
        size=n*2;
        p=new int[size];
        for(int i=0;i<n;i++){
            p[i]=s[n-i-1]-'0';
        }
    }
    BigInt(const BigInt &obj){Copy(obj);}
    BigInt(const BigInt *pobj){Copy(*pobj);}
    BigInt& operator=(const BigInt &obj){
        delete []p;
        Copy(obj);
        return *this;
    }
    ~BigInt(){
        delete []p;
    }
    friend ostream& operator<<(ostream& out,BigInt& obj){
        for(int i=obj.n-1;i>=0;i--){
            out<<obj.p[i]<<" ";
        }
        out<<endl;
        return out;
    }
};
int main(){
    BigInt x1(12345678);
    BigInt x2("1234567812345678");
    BigInt x3(x1);
    BigInt x4(&x2);
    cout<<x1<<endl;
    cout<<x2<<endl;
    cout<<x3<<endl;
    cout<<x4<<endl;

    return 0;
}