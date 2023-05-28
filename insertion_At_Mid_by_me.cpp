#include<iostream>
using namespace std;

class node{
  public:
  int data;
  node * next;
  
  node(int d){
    this->data = d;
    this->next = NULL;
  }
};

int get_length(node * &head){
  int len = 0;
  node * temp = head;
  while(temp != NULL){
    len++;
    temp = temp->next;
  }
  return len;
}

void insert_At_head(node * &head,int d){
  //step 1st: Create a new node;
  node * newnode = new node(d);
  
  //step 2nd: Tod fod waali backchodi and then you have to connect 
  newnode->next = head;
  
  //step 3rd: Update head;
  head = newnode;
}
void insert_At_tail(node *&tail,int d){
  //step 1st: Create a new node
  node * newnode = new node(d);
  
  //step 2nd: Tod fod waaali backchodi and then you have to connect;
  tail ->next = newnode;
  
  //update tail;
  tail = newnode;
}

void insert_At_mid(node *&head,int pos ,int val){
  //Edge Case: if the pos is greater then Linked List
  int len = get_length(head);
    if (pos >= len + 2) {
        cout << "This is not a valid position" << endl;
        return;  // Exit the function when position is invalid
    }
  //Edge Case: if the ele is insert at the first pos;
  if(pos == 1){
    insert_At_head(head,val);
    return;
  }
  //Edge Case: If the list is Empty;
  if(head == NULL){
    cout<<"List is empty ,Please insert some element "<<endl;
    return;
  }
  //step 1st : Create a new node;
  node * newnode = new node(val);
  
  //step 2nd: As we know we have to insert at mid toh hume ek pehle waale node tak pahuchna hoga;
  node * prev = head;
  // we will move forward this node untill we not reached at the previous node;
  
  int t = pos - 2;
  while(t--){
    prev = prev ->next;
  }
  
  newnode ->next = prev->next;
  prev->next = newnode;
}

void traverse(node * &head){
  node * temp = head;
  while(temp != NULL){
    cout<<temp->data<<endl;
    temp = temp->next;
  }
}
int main(){
  node * first_ele = new node(234);
  node * tail = first_ele;
  node * head = first_ele;
  insert_At_tail(tail,145);
   insert_At_tail(tail,245);
    insert_At_tail(tail,345);
     insert_At_tail(tail,445);
     insert_At_tail(tail,545);
    insert_At_tail(tail,645);
     insert_At_tail(tail,745);
     insert_At_tail(tail,845);
     
     node * head2 = NULL;
     
     insert_At_mid(head,11,4567);
     
     traverse(head);
  return 0;
}