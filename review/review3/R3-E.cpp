#include <bits/stdc++.h>
using namespace std;

struct Node{
    int x;
    Node* next;
    Node(int x):x(x),next(NULL){
        cout<<"Node()"<<x<<endl;
    }
    ~Node(){
        cout<<"~Node()"<<x<<endl;
    }
};  
class LinkList{
    Node *head;
public:
    LinkList():head(NULL){cout<<"LinkList()"<<endl;}
    void insert(int x){
        Node *np=new Node(x);
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
    ~LinkList(){
        Node *p=head;
        while(p!=NULL){
            Node *q=p;
            p=p->next;
            delete q;
        }
        cout<<"~LinkList()"<<endl;
    }
    void Output(){
        Node *p=head;
        while(p!=NULL){
            cout<<p->x<<" ";
            p=p->next;
        }
        cout<<endl;
    }
};
int main(){
    int n;
    cin>>n;
    LinkList T;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        T.insert(x);
    }
    T.Output();
    return 0;
}