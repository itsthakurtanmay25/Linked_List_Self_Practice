#include<iostream>
using namespace std;
class node{
  public:
  int data;
  node * next;
  
  //constructor
  node(int d){
    this->data = d;
    this->next = NULL;
  }
};

void insert_At_Head(node *& head,int d){
  //step 1st: Create a new node;
  node * temp = new node(d);
  
  //step 2nd: Tod fod ke connect kardo apne logic ke according;
  temp->next = head;
  
  //step 3rd : Update head
  head = temp;
}

void traverse(node * & head){
  node * temp = head;
  while(temp != NULL){
    cout<<temp->data<<endl;
    temp = temp->next;
  }
}
int main(){
  node * first_ele = new node(12);
  node * head = first_ele;
  
  insert_At_Head(head,34);
  insert_At_Head(head,78);
  insert_At_Head(head,98);
  insert_At_Head(head,346);
  insert_At_Head(head,98);
  insert_At_Head(head,12);
  insert_At_Head(head,876);
  
  traverse(head);

  return 0;
}