#include <bits/stdc++.h>
using namespace std;

struct Node{
    int c;//系数
    int e;//指数
    Node* next;
    Node(int x,int y):c(x),e(y){}
};
class PolyLinkList{
    Node *head;
public:
    PolyLinkList():head(NULL){}
    void push(int x,int y){
        Node *np=new Node(x,y);
        if(head==NULL){
            head=np;
        }else{
            Node *p=head;
            while(p->next!=NULL){
                p=p->next;
            }
            p->next=np;
        }
    }
    int add(int k){
        Node *p=head;
        int sum=0;
        while(p!=NULL){
            sum+=p->c*pow(k,p->e);
            p=p->next;
        }
        return sum;
    }   
    ~PolyLinkList(){
        Node *p=head;
        while(p!=NULL){
            Node *q=p;
            p=p->next;
            delete q;
        }
    }
};
int main(){
    int n;
    cin>>n;
    PolyLinkList P;
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        P.push(x,y);
    }
    int k;
    cin>>k;
    int sum=P.add(k);
    cout<<sum<<endl;

    return 0;
}