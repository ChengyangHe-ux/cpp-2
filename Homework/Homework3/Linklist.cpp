#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val):data(val),next(NULL){
        cout<<"Node()"<<val<<endl;
    }
    ~Node(){
        cout<<"~Node()"<<data<<endl;
    }
};
class LinkList {
    Node* head;
public:
    LinkList():head(NULL){
        cout<<"LinkList()"<<endl;
    }
    ~LinkList(){
        Node* p=head;
        while(p!=NULL){
            Node* q=p;
            p=p->next;
            delete q; 
        }
        cout<<"~LinkList()"<<endl;
    }
    void insert(int val){
        Node* newNode=new Node(val);
        if(head==NULL) {
            head=newNode;
        }else{
            Node* p=head;
            while(p->next!=NULL)
                p=p->next;
            p->next=newNode;
        }
    }
    void cout1(){
        Node* p=head;
        while(p!=NULL){
            cout<<p->data<<" ";
            p=p->next;
        }
        cout<<endl;
    }
};
int main() {
    int n;
    cin>>n;
    LinkList list;
    for(int i=0;i<n;i++) {
        int val;
        cin>>val;
        list.insert(val);
    }
    list.cout1();
    return 0;
}
