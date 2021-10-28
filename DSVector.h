//
// Created by Jeff's Laptop on 10/28/2021.
//

#ifndef INC_21F_FLIGHT_PLANNER_DSVECTOR_H
#define INC_21F_FLIGHT_PLANNER_DSVECTOR_H

using namespace std;


template <class T> class DSVector{
private:
    T* data;
    int curr;
    int capacity;

public:
    DSVector();
    DSVector(const DSVector&);
    ~DSVector();
    void push_back(T);
    void pop_back();
    void resize();
    void empty();
    int getLength();

    //operators
    T operator[](int);

};

//constructor
template <class T> DSVector<T>::DSVector(){
    data = new T[curr];         //allocates memory for an array of templated types
    curr = 0;                   //curr - the amount of elements with values currently in the array
    capacity = 10;              //capacity - the amount of total possible size for the array [not necessarily filled, just space allocated
}

//copy constructor
template <class T> DSVector<T>::DSVector(const DSVector& obj){ //copies the values of the DSVector to a clone DSVector
    obj.curr = curr;                //copies curr of the left side vector to the right side vector
    obj.capacity = capacity;        //copies the capacity of the left side vector to the right side vector
    obj.data = data;                //copies the data (aka the allocated space array) of the lhs vector to the rhs vector
}

//destructor
template <class T> DSVector<T>::~DSVector(){
    delete[] data;
}

//FUNCTION DECLARATIONS
template <class T> void DSVector<T>::push_back(T element){ //appends a type T object to the end of the vector
    if(curr == capacity){           //checks to see if the DSVector's current element has reached the capacity for the DSVector
        resize();                   //if so, resize (add 10 to capacity)
    }
    data[curr] = element;           //copies the parameter element into data at position curr
    curr++;                         //increases the current position, to account for the newly added element
}

template <class T> void DSVector<T>::pop_back(){ //removes the last element in the vector //needs work, this is definitely not how it is
    T* temp = new T[capacity];  //creates a copy array
    for(int i = 0; i < curr-1; i++){       //until the second to last element
        temp[i] = data[i];
    }
    curr--;             //lowers curr by 1
    delete[] data;      //deletes the old data, restoring it with the temp elements
    data = temp;
}

template <class T> void DSVector<T>::resize(){  //creates a new vector with more capacity, recognition of the fact that curr = capacity is not included, and is necessary to implement in other functions before calling
    T* temp = new T[capacity + 10];             //creates a new T* array of size capacity + 10
    for(int i = 0; i < capacity; i++){          //copies the values from data into temp
        temp[i] = data[i];
    }
    capacity = capacity + 10;                   //changes the stored private capacity variable accordingly
    delete[] data;                              //deletes the old data memory
    data = temp;                                //copies the new temp memory into data
}

template <class T> void DSVector<T>::empty(){
    for(int i = 0; i < curr; i++){  //does the pop_back functionality for every single element
        T* temp = new T[capacity];  //creates a copy array
        for(int i = 0; i < curr-1; i++){       //until the second to last element
            temp[i] = data[i];
        }
        curr--;             //lowers curr by 1
        delete[] data;      //deletes the old data, restoring it with the temp elements
        data = temp;
    }
}

//overloading the arr idx operator
template <class T> T DSVector<T>::operator[](int index){
    return data[index];            //returns the index # element of the data array
}

template <typename T> int DSVector<T>::getLength(){
    return curr;
}

#endif //INC_21F_FLIGHT_PLANNER_DSVECTOR_H
