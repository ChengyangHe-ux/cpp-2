#include <bits/stdc++.h>
using namespace std;

class Node {
public:    
    int x;
    Node *next;
    Node(int x):x(x){ next = NULL; }
};

class LinkList {
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
        Node* np = new Node(x);
        if(head == NULL){
            head = np;
        }else{
            Node* p = head;
            while(p->next != NULL){
                p = p->next;
            }
            p->next = np;
        }
        Count++;
    }

    bool contains(int x){
        Node* p = head;
        while(p){
            if(p->x == x) return true;
            p = p->next;
        }
        return false;
    }

    void print(){
        Node* p = head;
        while(p){
            cout << p->x << " ";
            p = p->next;
        }
        cout << endl;
    }

    int& operator[](int x){
        Node *p = head;
        for(int i=0;i<x;i++){
            p = p->next;
        }
        return p->x;
    }

    ~LinkList(){
        Node* p = head;
        while(p != NULL){
            Node* np = p;
            p = p->next; 
            delete np;
        }
        cout << "~LinkList()" << Count << endl;
    }
};

int main(){
    int na, nb;
    cin >> na;
    LinkList A;
    for(int i=0;i<na;i++){
        int x;
        cin >> x;
        A.push(x);
    }    
    cout << "LinkList()" << A.Count << endl;

    cin >> nb;
    LinkList B;
    for(int i=0;i<nb;i++){
        int x;
        cin >> x;
        B.push(x);
    }
    cout << "LinkList()" << B.Count << endl;

    LinkList C;
    for(int i=0;i<na;i++){
        if(B.contains(A[i])){
            C.push(A[i]);
        }
    }
    cout << "LinkList()" <<0<< endl;

    C.print(); // 输出交集元素

    return 0;
}
