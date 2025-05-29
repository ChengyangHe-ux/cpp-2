#include <bits/stdc++.h>
using namespace std;
class Node{
public:    
    int x;
    Node *next;
    Node(int x):x(x){next=NULL;}
};

class LinkList{
    Node* head;
public:    
    int Count;
    LinkList():Count(0),head(NULL){}
    LinkList(LinkList &obj):head(NULL),Count(0){
        Node* p=obj.head;
        while(p!=NULL){
            push(p->x);
            p=p->next;    
        }
    }
    void push(int x){
        Node* np=new Node(x);
        if(head==NULL){
            head=np;
        }else{
            Node* p=head;
            while(p->next!=NULL){
                p=p->next;
            }
            p->next=np;
        }
        Count++;
    }
    int& operator[](int x){
        Node *p=head;
        for(int i=0;i<x;i++){
            p=p->next;
        }
        return p->x;
    }
    ~LinkList(){
        Node* p=head;
        while(p!=NULL){
            Node* np=p;
            p=p->next; 
            delete np;
            Count--;
        }
    }
};
int main(){
    LinkList L1;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        L1.push(x);
    }
    LinkList L2(L1);
    int i;
    for(i=0; i<L2.Count; i++) L2[i]=L2[i]+1;
    int L1Sum=0;
    for(i=0; i<L1.Count; i++) L1Sum+=L1[i];
    int L2Sum=0;
    for(i=0; i<L2.Count; i++) L2Sum+=L2[i];
    cout<<L1Sum<<" "<<L2Sum<<endl;
    return 0;
}