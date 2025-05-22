#include <bits/stdc++.h>
using namespace std;

struct PolyLinkNode {
    int c; 
    int e; 
    PolyLinkNode* next;
    PolyLinkNode(int c,int e):c(c),e(e),next(NULL){}
};
class PolyLinkList {
    PolyLinkNode* head;
public:
    PolyLinkList():head(NULL){}
    void push_front(int c,int e) {
        PolyLinkNode* np=new PolyLinkNode(c,e);
        np->next=head;
        head=np;
    }
    void insert(int c,int e){
        if(c==0) return;
        PolyLinkNode* np=new PolyLinkNode(c,e);
        if (head==NULL||head->e<e) {
            np->next=head;
            head=np;
            return;
        }
        PolyLinkNode* prev=NULL,*now=head;
        while (now!=NULL&&now->e>e){
            prev=now;
            now=now->next;
        }
        if (now!=NULL&&now->e==e){
            now->c+=c;
            if(now->c==0){
                if(prev)prev->next=now->next;
                else head=now->next;
                delete now;
            }
            delete np;
        } else {
            np->next=now;
            if(prev!=NULL)prev->next=np;
            else head=np;
        }
    }
    int Sum(int x) {
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
    PolyLinkList add(const PolyLinkList& other){
        PolyLinkList result;
        PolyLinkNode* pa=this->head;
        PolyLinkNode* pb=other.head;
        while (pa||pb) {
            if(pb==NULL||(pa&&pa->e>pb->e)){
                result.insert(pa->c,pa->e);
                pa=pa->next;
            }else if(pa==NULL||pb->e>pa->e){
                result.insert(pb->c,pb->e);
                pb=pb->next;
            }else{
                result.insert(pa->c+pb->c,pa->e);
                pa=pa->next;
                pb=pb->next;
            }
        }
        return result;
    }
    PolyLinkList mul(const PolyLinkList& other){
        PolyLinkList result;
        for(PolyLinkNode* pa=head;pa!=NULL;pa=pa->next){
            for(PolyLinkNode* pb=other.head;pb!=NULL;pb = pb->next) {
                result.insert(pa->c*pb->c,pa->e+pb->e);
            }
        }
        return result;
    }
    void Output() {
        PolyLinkNode* p=head;
        while(p!=NULL){
            cout<<p->c<<" "<<p->e<<" ";
            p=p->next;
        }
        cout<<endl;
    }
    ~PolyLinkList() {
        while(head!=NULL) {
            PolyLinkNode* t=head;
            head=head->next;
            delete t;
        }
    }
};
int main() {
    int na,nb;
    cin>>na;
    PolyLinkList Pa;
    for(int i=0;i<na;i++) {
        int c,e;
        cin>>c>>e;
        Pa.push_front(c,e);
    }
    cin>>nb;
    PolyLinkList Pb;
    for(int i=0;i<nb;i++) {
        int c,e;
        cin>>c>>e;
        Pb.push_front(c, e);
    }
    PolyLinkList sum=Pa.add(Pb);
    PolyLinkList prod=Pa.mul(Pb);
    sum.Output();
    prod.Output();
    return 0;
}
