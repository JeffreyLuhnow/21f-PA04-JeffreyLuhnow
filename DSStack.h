//
// Created by Jeff's Laptop on 10/27/2021.
//
#ifndef INC_21F_FLIGHT_PLANNER_DSSTACK_H
#define INC_21F_FLIGHT_PLANNER_DSSTACK_H

#include "DSLList.h"
#include "DSVector.h"
#include <string>

using namespace std;

#define SIZE 10

template <class T> class DSStack{
private:
    DSLList<T> *list;      //doubly linked list
    DSVector<T> flightList; //vector
    int top;            //top of the LIFO
    int capacity;       //how much the stack can hold
public:
    DSStack(int size = 0); //constructor
    DSStack(const DSStack&); //copy constructor
    ~DSStack();
    void push(T); //adds to stack
    T pop(); //removes from stack
    T peek(); //observe location
    bool isEmpty(); //bool to check if it is empty
    bool isFull(); //bool to check if it is full
    int getSize(); //returns the size of the stack
    void clear(); //clears the stack
};


//CONSTR, COPY CONSTR, AND DESTR
template <class T>
DSStack<T>::DSStack(int size){ //constructor
    flightList = new T[size];
    capacity = size;
    top = -1;
}
template <class T>
DSStack<T>::DSStack(const DSStack& obj){ //copy constructor
    obj.flightList = flightList;
    obj.capacity = capacity;
    obj.top = top;
}
template <class T>
DSStack<T>::~DSStack(){ //destructor
    delete[] flightList;
}

//MEMBER FUNCTIONS OF THE CLASS DSSTACK

//clears the stack
template <class T>
void DSStack<T>::clear(){
    for(int i = 0; i < top; i++){
        flightList[top--];
    }
}

//adds an element to the stack
template <class T>
void DSStack<T>::push(T element){
    if(isFull() == true){ //if the stack is full, add more capacity and insert the element at the top
        capacity += 10;
        flightList[++top] = element;
    }
    else{               //if it's not full add the element but keep capacity unchanged
        flightList[++top] = element;
    }
}

//removes an element from the stack
template <class T>
T DSStack<T>::pop(){
    if(isEmpty() == true){    //if the stack is empty, return an error message and do not try to remove an element
        cout << "STACK EMPTY, CANNOT REMOVE ELEMENT" << endl;
    }
    else{                   //if the stack is NOT empty, remove the top element, and then set the top to one less
        return flightList[top--];
    }
}

//reveals the element in the stack at the top
template <class T>
T DSStack<T>::peek(){
    if(isEmpty() == true){        //if the stack is empty, cannot return an element, return error message
        cout << "Error: Stack is empty, no elements inside" << endl;
    }
    else{           //if the stack is NOT empty, return the element at the "top"
        return flightList[top];
    }
}

//if empty, returns true, if not empty, returns false
template <class T>
bool DSStack<T>::isEmpty(){
    if(top == -1){
        return true;
    }
    else{
        return false;
    }
}

//if full, return true, if not, return false
template <class T>
bool DSStack<T>::isFull(){
    if(top == capacity - 1){
        return true;
    }
    else{
        return false;
    }
}

//returns the size of the stack
template <class T>
int DSStack<T>::getSize(){
    return top + 1;
}
#endif //INC_21F_FLIGHT_PLANNER_DSSTACK_H
