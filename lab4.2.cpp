//Program to implement queue using 2 stacks

// including library
#include<iostream>

//using namespace
using namespace std;

// class
class Node
{
public:
           //storing data
           int data;
           //pointer to move to next node
            Node* next;
           //initializing next pointer as NULL
            Node(){
           next = NULL;
          }
};
class LinkedList{
public:
            //pointer to store start node of the linked list
            Node* head;
           //pointer to point to the last node of the linked list
            Node *tail;
           //initializing head as NULL
    LinkedList(){
                head = NULL;
                tail = NULL;
                }
    void insert(int value){
                         Node *temp = new Node;
                         temp->data = value;
                        if(head==NULL){
                        //update head;
                        head = temp;
                        }
                        else{
                        //linking the last element to new node created
                            tail->next = temp;
                            }
                        //update tail
                        tail = temp;
                        cout<<endl;
                         }


    //Deleting
    //deleting the end element
    void deletion(){
                 Node *temp = tail;
                Node *current = head;
                 while(current->next != tail){
                                            current = current->next;
                                            }
                  current->next = NULL;
                //updating tail
                tail = current;
                //deleting temp
                delete temp;
               cout<<endl;
                }
                 void insertAt(int pos,int value){
                //To add node at the position of the header
               if(pos == 1){
                          Node *temp = new Node;
                          temp->data = value;
                          //linking the new node to head
                          temp->next = head;
                         //updating head
                         head = temp;
                        }
              else{
                  //Reaching the place before the position
                   Node *current = head;
                   int i = 1;
                  while(i<pos-1){
                                i++;
                                current = current->next;
                                 }
                  //counter variable to count no. of entries
                  int count = 0;
                //declaring present pointer to initially point to head
               Node *present = head;
                //increment count upto last element and simultaneously increment present pointer
               while(present!=NULL){
                                   count++;
                                   present = present->next;
                                  }
            if(pos>count){
                        cout<<"The linked list doesn't have that many elements\n";
                         }
            else{
                //Create the node
                Node *temp = new Node;
                temp->data = value;
                //Moving pointers like magic
                temp->next = current->next;
                current->next = temp;
                }
            }
            cout<<endl;
            }
    //Deleting element of linked list from a specific position
    void deletionAt(int pos){
                         if(pos == 1){
                                     if(head != NULL){
                                                     Node *temp = head;
                                                     head = head->next;
                          //deleting temp
                         delete temp;
                           }
        }
        else{
            //reachs the position just before the node to be deleted
            Node *current = head;
            int i = 1;
            while(i<pos-1){
                          i++;
                          current = current->next;
                        }
            Node *temp = new Node;
            temp = current->next;
            current->next = temp->next;
            //deleting temp
            delete temp;
           }
        cout<<endl;
    }
    //Displaying
    void display(){
                   Node *current = head;
                   while(current != NULL){
                                       cout<<current->data<<"->";
                                       current = current->next;
                                        }
                   cout<<"NULL";
                   }
    //Counting
    int countItems(){
        //set a counter variable
        int count = 0;
        Node *current = head;
        while(current !=NULL){
                             count++;
                             current = current->next;
                            }
        return count;
        }
};
//stack using linked list
class StackLL{
public:
    Node *top;
    LinkedList l1;
    StackLL(){
        top = NULL;
    }
    //pushes on top
    void push(int value){
                       l1.insertAt(1,value);
                      top = l1.head;
                        }
    //pops from top
    void pop(){
              l1.deletionAt(1);
              top = l1.head;
               }
    //checks whether the stack is empty
    bool isEmpty(){
                  if(top == NULL)
                  return true;
                  return false;
                  }
    //returns size of the stack
    int size(){
              return l1.countItems();
              }
    //displays value stored in top pointer
    void topDisplay(){
                     cout<<"Value in top pointer: "<<top->data<<endl;
                        }
    //display
    void display(){
                  l1.display();
                   }
};
class Queue{
public:
    //creating two stacks
    StackLL s1,s2;
    //adds elements to the queue
    void enqueue(int value){
                          s1.push(value);
                             }
    //deletes elements from the queue
    void dequeue(){
                   if(s1.size()==0)
			       return; //Newline
                   if(s1.size()==1){
                    s1.pop();
                    return;
                  }
        else{
            //pushes data from main stack to another stack
            s2.push(s1.top->data);
            //pops element from main stack
            s1.pop();
            cout << "S1 :"; s1.display(); cout << endl; //Newline
            cout << "S2 :"; s2.display(); cout << endl; //Newline
            dequeue();
            //pushes elements back into the main stack
            s1.push(s2.top->data);
            s2.pop();
        }
    }
    //displaying the contents of the queue
    void display(){
        s1.display();
        cout<<endl;
    }
    //returns the size of the queue
    int size()
    {
        return s1.size();
    }
};
//including main function
int main(){
    Queue q1;
    for(int i=1;i<6;i++){
                       q1.enqueue(i);
                        }
    //dequeueing twice
    q1.display();
    q1.dequeue();
    q1.display();
	q1.dequeue();
	q1.display();
    return 0;
}
