#include <iostream>
#include <vector>
using namespace std;

class food{
public:
    virtual int eattime()=0;
};
class apple:public food
{
    virtual int eattime(){return 30;}
};
class banana:public food
{   
    virtual int eattime(){return 15;}
};
class pears:public food
{
    virtual int eattime(){return 5;}
};
class foods{
    vector<food *>M;
public:
    void append(food *p ){
        M.push_back(p);
    }
    void sum(){
        int ans=0;
        for(int i=0;i<M.size();i++){
            ans+=M[i]->eattime();
        }
        cout<<ans<<endl;
    }
};
int main(){
    foods M;
    M.append(new apple);
    M.append(new banana);
    M.append(new pears);
    M.sum();
    return 0;
}