#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;

    node(int x){
        data=x;
        next=NULL;
    }
};

class linkedlist{
    private:
    node* head;
    public:

    linkedlist(){
        head=NULL;
    }

    void insert(int x){
        node* p=new node(x);

        if(head==NULL){
            head=p;
            return;
        }

        node* q=head;
        while(q->next!=NULL){
            q=q->next;
        }
        q->next=p;
    }

    void display(){
        node* q=head;
        while(q!=NULL){
            cout<<q->data<<"-> ";
            q=q->next;

        }
        cout<<endl;
        
    }

    void remove(int x){
        node* p=NULL;
        node* q=head; 

        if(head->data==x){
            head=p;
            head=head->next;
            delete p;
            return;
        }

        while(q->next!=NULL){
            if(q->next->data==x){
               p= q->next;
                q->next=p->next;
                delete p;
                return;
            }
            q=q->next;
        }
    }

    void sort(){
        bool swapped;
        do{
            swapped=false;

            node* q=head;
            while(q->next!=NULL){
            if(q->data>q->next->data){
                int temp=q->data;
                q->data=q->next->data;
                q->next->data=temp;
                swapped=true;
            }
            q=q->next;
            }

        }
        while(swapped);
    }
};

int main(){
    linkedlist list;

    list.insert(20);
    list.insert(10);
    list.insert(30);
    list.insert(50);
    list.insert(40);

    list.display();

    list.remove(30);
    list.display();

    list.sort();
    list.display();

    return 0;

}

//PS C:\practice> cd "c:\practice\" ; if ($?) { g++ 5.cpp -o 5 } ; if ($?) { .\5 }
// 20-> 10-> 30-> 50-> 40-> 
// 20-> 10-> 50-> 40-> 
// 10-> 20-> 40-> 50-> 
// PS C:\practice> 

