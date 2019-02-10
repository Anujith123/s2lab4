//Program to create a stack using queue(s)

// including library
#include<iostream>
// using namespace std
using namespace std;

//including class
class Node{
   public:
	     //stores data
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
	          Node *head;
	         //pointer to point to the last node of the linked list
	         Node *tail;
	         //initializing head as NULL
	          LinkedList(){
		                head = NULL;
		                tail = NULL;
                        }
	void insert(int value){
		                  //createing new node temp
		                  Node *temp = new Node;
                          //sets value as data of the node
		                  temp->data = value;
		                   //shows first element is being inserted
		     if(head==NULL)                                                    //if else condition
		     {
			              //updateing head;
			               head = temp;
		                   }
		else{
			//link last element to new node created
			tail->next = temp;
		}
		//update tail
		tail = temp;
		cout<<endl;
	}
//Deletion
	void deletion(){
		//storing the tail in temp
		Node *temp = tail;
		Node *current = head;
		//objective is to stop current upto node just before tail
		while(current->next != tail){
			                        current = current->next;
		                           }
		current->next = NULL;
		//updating the tail
		tail = current;
		//deleting temp
		delete temp;
		cout<<endl;
	}
	void insertAt(int pos,int value){
		if(pos == 1){
			//creating a new node
			Node *temp = new Node;
			//assign the entered value as data to the new node
			temp->data = value;
			//link the new node to head
			temp->next = head;
			//updating head
			head = temp;
		}
		else{
			//Reach the place before the position
			Node *current = head;
			int i = 1;
			while(i<pos-1){
				           i++;
				           current = current->next;
			}
			//counter variable to count no. of entries
			int count = 0;
			//declares present pointer to initially point to head
			Node *present = head;
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
				//Moving pointers like
				temp->next = current->next;
				current->next = temp;
			}
		}
		cout<<endl;
	}

	//Deleting the element of linked list from a specific position
	void deletionAt(int pos){
		if(pos == 1){
			if(head != NULL){
				            //sets the node to be deleted as temp
				            Node *temp = head;
				            head = head->next;
                            //deleting temp
				           delete temp;
			}
		}
		else{
			//reach the position just before the node to be deleted
			Node *current = head;
			int i = 1;
			while(i<pos-1){
                        i++;
				        current = current->next;
			}
			//Creates the node temp and set it as the node to be deleted
			Node *temp = new Node;
			temp = current->next;
			current->next = temp->next;
			//deleting temp
			delete temp;
	   	 }
		cout<<endl;
	}
	//printing
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
		//return the counter
		return count;
	}
};
//implements linked list to create a queue
class QueueLL{
   public:
	Node *front;
	Node *end;
	LinkedList l2;
	//initializes front and end to NULL
	QueueLL(){
		front = NULL;
		end = NULL;
	}
	//adding element at the start
	void enqueue(int value){
		                  l2.insertAt(1,value);
		                  Node *current = l2.head;
		while(current->next!=NULL){
			current = current->next;
		                   }
		//update front and end pointers
		front = current;
		end = l2.head;
	}
	//removes element from the end
	void dequeue(){
		l2.deletionAt(l2.countItems());
		Node *current = l2.head;
		while(current->next!=NULL){
			current = current->next;
		                           }
		//update front and end pointers
		front = current;
		end = l2.head;
	}
	//returning size of the queue
	int size(){
		return l2.countItems();
	}
	//checking if the queue is empty
	bool isEmpty(){
		if(front == NULL)
		    return true;
		return false;
	}
	//displaying the data in front and end pointers
	void frontendDisplay(){
		//front data
		cout<<"Front pointer data: "<<front->data<<endl;

		//end data
		cout<<"End pointer data: "<<end->data<<endl;
	}

	//displaying the contents of the queue
	void display(){
		l2.display();
	             }
};
class Stack{
   public:
   	//creating queue
   	QueueLL q1;

   	//pushes element into stack
   	void push(int value)
   	{
   		q1.enqueue(value);
   	}

   	//pops element from the stack
   	void pop(){
		for(int i=1;i<q1.size();i++){
			q1.enqueue(q1.front->data);
			q1.dequeue();
		}
		q1.dequeue();
		return;
   	}
   	//returning the size of the stack
   	int size(){
   		return q1.size();
   	}
   	//displaying the contents of the stack
   	void display(){
   		q1.display();
   		cout<<endl;
   	              }
   	//checking if the stack is empty
   	bool isEmpty(){
   		return q1.isEmpty();
	}
};
//including main function
int main(){
	Stack s1;
	for(int i=1;i<6;i++){
		               s1.push(i);
	                    }
	s1.display();
	s1.pop();
	s1.display();
	s1.pop();
	s1.display();
	return 0;
}
