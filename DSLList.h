#ifndef INC_21F_FLIGHT_PLANNER_DSLLIST_H
#define INC_21F_FLIGHT_PLANNER_DSLLIST_H

#include <iostream>

using namespace std;

//NODE CLASS
template <class T>
class DSNode {
public:
    T data;         //provides element of type T
    DSNode *prev;   //pointer pointing to the next node
    DSNode *next;   //pointer pointing to the previous node
};

//DSLLIST CLASS
template <class T>
class DSLList{
private:
    DSNode<T> *head;  //pointer of type DSNode (templated)
    DSNode<T> *tail;  //pointer of type DSNode (templated)
    int size = 0;
public:
    DSLList(){
        head = new DSNode<T>(); //first element of the list, allocates space for a DSNode object
        tail = new DSNode<T>(); //last element of the list, allocates space for a DSNode object
    }
    ~DSLList(){
        clear();
        delete head; //frees memory for head (first)
        delete tail; //frees memory for tail (last)
    }

    //sizeOfList function
    int sizeOfList(){
        return size;
    }

    //isEmpty function
    bool isEmpty(){
        if(head->next == NULL){
            return true;
        }
        else{
            return false;
        }
    }

    //insert function for inserting at the head (first)
    void insertHead(T &d){
        if(isEmpty() == true){                  //if the list is empty, allocate space for a node (with data as the parameter), set next and prev to point to this new node
            DSNode<T> *newNode = new DSNode<T>(d);
            head->next = newNode;
            tail->prev = newNode;
            size++;
        }
        else{                                   //if the list is NOT empty, set the current node to next, create a new node (with data and the current node as parameters), set next and prev to point to this new node
            DSNode<T> *currentFirst = head->next;
            DSNode<T> *newNode = new DSNode<T>(d, currentFirst);
            currentFirst->prev = newNode;
            head->next = newNode;
            size++;
        }
    }

    //insert function for inserting at the tail (last)
    void insertTail(T &d){
        if(isEmpty() == true){
            DSNode<T> *newNode = new DSNode<T>(d);  //allocates space for a new node which holds data
            head->next = newNode;   //sets the next and prev pointers to point to the newly created Node
            tail->prev = newNode;
            size++;
        }
        else{
            DSNode<T> *currentLast = tail->prev;
            DSNode<T> *newNode = new DSNode<T>(d, NULL, currentLast); //parameter 1 governs the element, 2 governs the "next" ptr, and 3 governs the "prev" ptr
            currentLast->next = newNode;     //sets the next and prev pointers to point to the new node
            tail->prev = newNode;
            size++;
        }
    }

    //function to clear the list
    void clear(){
        while(tail->prev != NULL){          //while there is still an element pointed to by the "prev" pointer (aka, until nothing is pointing to by prev)
            DSNode<T> *buffer = tail->prev; //create a buffer DSNode, set to the value pointed to by prev
            tail->prev = buffer->prev;      //set the value pointed to by tail to the new buffer pointer
            delete buffer;                  //deletes the node
            size = 0;
        }
    }

};

#endif

//add a pop/remove functions
//change stack to use linked list


