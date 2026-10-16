// intlist.cpp
// Implements class IntList
//Wenjia Xu, 2026-10-16

#include "intlist.h"

#include <iostream>
using std::cout;

//to this list, deleting/replacing any existing nodes
IntList& IntList::operator=(const IntList& source){
    if(this==&source){
    return *this;
    }
    Node *temp=head;
    while(temp){
        Node *nextNode=temp->next;
        delete temp;
        temp=nextNode;
    }
    head=nullptr;
    if(source.head){
         head=new Node;
    head->info=source.head->info;
    head->next=nullptr;
    Node *s=source.head->next;
    Node *n=head;
    while(s){
        n->next=new Node;
        n=n->next;
        n->info=s->info;
        n->next=nullptr;
        s=s->next;
    }
    }
    return *this;
}

// copy constructor
IntList::IntList(const IntList& source) {
    //IMPLEMENT THIS
    if(!source.head){
        head=nullptr;
        return;
    }
    head=new Node;
    head->info=source.head->info;
    head->next=nullptr;
    Node *s=source.head->next;
    Node *n=head;
    while(s){
        n->next=new Node;
        n=n->next;
        n->info=s->info;
        n->next=nullptr;
        s=s->next;
    }

}

// destructor deletes all nodes
IntList::~IntList() {
    Node *temp=head;
    while(temp){
        Node *nextNode=temp->next;
        delete temp;
        temp=nextNode;
    }
    head=nullptr;
}


// return sum of values in list
int IntList::sum() const {
    int sum=0;
    Node *temp=head;
    while(temp){
        sum+=temp->info;
        temp=temp->next;
    }
    return sum; // REPLACE THIS NON-SOLUTION
}

// returns true if value is in the list; false if not
bool IntList::contains(int value) const {
    Node *temp=head;
    while(temp){
        if(temp->info==value){
            return true;
        }
        temp=temp->next;
    }
    return false; // REPLACE THIS NON-SOLUTION
}

// returns maximum value in list, or 0 if empty list
int IntList::max() const {
    if(!head){
        return 0;
    }
    int max=head->info;
    Node *temp=head;
    while(temp){
        if(temp->info>max){
            max=temp->info;
        }
        temp=temp->next;
    }
    return max; // REPLACE THIS NON-SOLUTION
}

// returns average (arithmetic mean) of all values, or
// 0 if list is empty
double IntList::average() const {
    int number=count();
    if(number==0){
        return 0.0;
    }
    return static_cast<double>(sum())/number; // REPLACE THIS NON-SOLUTION
}

// inserts value as new node at beginning of list
void IntList::push_front(int value) {
   Node *newNode=new Node;
   newNode->info=value;
   newNode->next=head;
   head=newNode;
}

// append value at end of list
void IntList::push_back(int value) {
    Node *newNode=new Node;
    newNode->info=value;
    newNode->next=nullptr;
    if(!head){
        head=newNode;
        tail=newNode;
    }
    else{
        tail->next=newNode;
        tail=newNode;
    }
 
}

// return count of values
int IntList::count() const {
   int counter=0;
   Node *temp = head;
   while(temp){
    counter++;
    temp=temp->next;
   }
   return counter;
}


//Assignment operator should copy t

// constructor sets up empty list
IntList::IntList(){ 
    //IMPLEMENT THIS 
    head=nullptr;
}


// DO NOT CHANGE ANYTHING BELOW (READ IT THOUGH)

// print values enclose in [], separated by spaces
void IntList::print() const {
    Node *n = head;
    cout << '[';
    while (n) {
        cout << n->info;
        if (n->next)
            cout << " ";
        n = n->next;
    }
    cout << ']';
}

