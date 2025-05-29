#include <bits/stdc++.h>
using namespace std;

struct PolyListNode{
    int c;//系数
    int e;//指数
    bool operator==(const PolyListNode& obj){
        return this->e==obj.e;
    }
    bool operator<(const PolyListNode& obj){
        return this->e>obj.e;
    }
};

class PolyList{
    vector<PolyListNode> T;
    int n;
public:
    PolyList(int n=0,int b[]=NULL):n(n){
        T.resize(n);
        for(int i=0,j=0;i<2*n-1;i+=2,j++){
            T[j].c=b[i];
            T[j].e=b[i+1];
        }
        sort(T.begin(),T.end());
    }
    int solve(int x){
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=(T[i].c*pow(x,T[i].e));
        }
        return sum;
    }
    PolyList myadd(PolyList &obj){
        PolyList C;
        int i=0,j=0;
        while(i<n&&j<obj.n){
            if(T[i].e==obj.T[j].e){
                int sum=T[i].c+obj.T[j].c;
                if(sum!=0){
                    C.T.push_back({sum,T[i].e});
                }
                i++;j++;
            }else if (T[i].e > obj.T[j].e) {
                C.T.push_back(T[i]);
                i++;
            }
            else {
                C.T.push_back(obj.T[j]);
                j++;
            }
        }
        while (i < n) {
            C.T.push_back(T[i]);
            i++;
        }
        while (j < obj.n) {
            C.T.push_back(obj.T[j]);
            j++;
        }
        
        C.n = C.T.size(); // 更新项数
        return C; // 返回新对象
    }
    friend ostream& operator<<(ostream &out,const PolyList &Tm){
        for(int i=0;i<Tm.n;i++){
            out<<Tm.T[i].c<<" "<<Tm.T[i].e<<" ";
        }
        return out;
    }
    ~PolyList(){}
};
int main(){
    int n;
    cin>>n;
    int b[100];
    for(int i=0;i<2*n;i++){
        cin>>b[i];
    }
    PolyList M(n,b);
    int m;
    cin>>m;
    int c[100];
    for(int i=0;i<2*m;i++){
        cin>>c[i];
    }
    PolyList N(m,c);
    PolyList MM;
    MM=(M.myadd(N));
    cout<<MM;
    return 0;
}