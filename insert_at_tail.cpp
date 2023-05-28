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

void insert_At_tail(node *& tail,int d){
  //step 1st: Create a new node;
  node * temp = new node(d);
  
  //step 2nd: Tod fod ke connect kardo apne logic ke according;
  tail->next = temp;
  
  //step 3rd : Update head
  tail = temp;
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
  node * tail = first_ele;
  
  insert_At_tail(tail,78);
  insert_At_tail(tail,98);
  insert_At_tail(tail,34);
  insert_At_tail(tail,346);
  insert_At_tail(tail,98);
  insert_At_tail(tail,12);
  insert_At_tail(tail,876);
  
  traverse(head);

  return 0;
}