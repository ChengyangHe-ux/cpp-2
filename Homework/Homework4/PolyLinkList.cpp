#include <bits/stdc++.h>
using namespace std;
struct PolyLinkNode{
    int c;
    int e;
    PolyLinkNode* next;
    PolyLinkNode(int c,int e):c(c),e(e),next(NULL){}
};
class PolyLinkList{
    PolyLinkNode* head;
public:
    PolyLinkList(){
        head=NULL;
    }
    void push_front(int c,int e){
        PolyLinkNode* np=new PolyLinkNode(c,e);
        np->next=head;
        head=np;
    }
    int Sum(int x){
        int ans=0;
        PolyLinkNode* p=head;
        while(p!=NULL){
            int t=1;
            for(int i=0;i<p->e;i++){
                t*=x;
            }
            ans+=p->c*t;
            p=p->next;
        }
        return ans;
    }
    ~PolyLinkList(){
        while(head!=NULL){
            PolyLinkNode* t=head;
            head=head->next;
            delete t;
        }          
    }
};
int main(){
    int n;
    cin>>n;
    PolyLinkList P;
    for(int i=0;i<n;i++){
        int c,e;
        cin>>c>>e;
        P.push_front(c,e);
    }
    int x;
    cin>>x;
    cout<<P.Sum(x)<<endl;
    return 0;
}