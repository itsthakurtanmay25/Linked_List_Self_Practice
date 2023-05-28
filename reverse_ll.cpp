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
  
  void insert_At_tail(node *&tail,int d){
    //step 1st: Create a new node;
    node * temp = new node(d);
    
    //step 2nd: Tod fod waali backchodi and apne logic ke according connection dedo;
    tail->next = temp;
    
    //step 3rd: Update tail;
    tail = temp;
  }
  
  void deletion_at_head(node *&head){
    node * temp = head;
    head = head -> next;
    temp ->next = NULL;
    delete temp;
  }
  
  void deletion_at_tail(node  *&head){
    node * prev = NULL;
    node * curr = head;
    while(curr -> next != NULL){
      prev = curr;
      curr = curr->next;
    }
    prev->next = NULL;
    delete curr;
  }
  
  node * reverse(node *& head){
    node * prev = NULL;
    node * curr = head;
    node * forward = NULL;
    
    while(curr != NULL){
      forward = curr ->next;
      curr->next = prev;
      prev = curr;
      curr = forward;
    }
    return prev;
  }
  
  void traverse(node *&head){
    node *temp = head;
    while(temp != NULL){
      cout<<temp->data<<" ";
      temp = temp->next;
    }
    cout<<endl;
  }
};

int main(){
  node * first_node = new node(122);
  node * tail = first_node;
  node * head = first_node;
  first_node->insert_At_tail(tail,123);
  first_node->insert_At_tail(tail,119);
  first_node->insert_At_tail(tail,121);
  first_node->insert_At_tail(tail,178);
  first_node->insert_At_tail(tail,1);
  first_node->insert_At_tail(tail,67);
  first_node->insert_At_tail(tail,93);
  first_node->insert_At_tail(tail,873);
  
  first_node->deletion_at_head(head);
  first_node->deletion_at_tail(head);
  first_node->deletion_at_tail(head);
  
  cout<<"Before Reverse : "<<endl;
  first_node->traverse(head);
  head = first_node->reverse(head);
  
  cout<<"After Reverse : "<<endl;
  first_node->traverse(head);
  
  return 0;
}