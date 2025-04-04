#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node(int val):data(val),next(NULL){}
};
class LinkList {
private:
    Node* head;
public:
    int Count;
    void insert(int val){
        Node* newNode=new Node(val);
        if(head==NULL) {
            head=newNode;
        }else{
            Node* p=head;
            while(p->next){
                p=p->next;
            }
            p->next=newNode;
        }
        Count++;
    }
    LinkList() {
        head=NULL;
        Count=0;
    }
        LinkList(istream& in) {
        head=NULL;
        Count=0;
        int n;
        in>>n;
        for(int i=0;i<n;i++) {
            int x;
            in>>x;
            insert(x);
        }
    }
    LinkList(const LinkList& other) {
        head=NULL;
        Count=0;
        Node* p=other.head;
        while(p){
            insert(p->data);
            p=p->next;
        }
    }
    int& operator[](int index) {
        Node* p=head;
        for(int i=0;i<index&&p;i++) {
            p=p->next;
        }
        return p->data;
    }
    ~LinkList(){
        Node* p=head;
        while(p){
            Node* q=p;
            p=p->next;
            delete q;
        }
    }
};
int main()
{
    LinkList L1(cin); 
    LinkList L2(L1);    
    for(int i=0;i<L2.Count;i++)L2[i]=L2[i]+1;
    int L1S=0,L2S=0;
    for(int i=0;i<L1.Count;i++)L1S+=L1[i];
    for(int i=0;i<L2.Count;i++)L2S+=L2[i];
    cout<<L1S<<" "<<L2S<<endl;
    return 0;
}
