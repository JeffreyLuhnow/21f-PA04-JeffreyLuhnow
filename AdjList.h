//
// Created by Jeff's Laptop on 10/31/2021.
//

#ifndef INC_21F_FLIGHT_PLANNER_ADJLIST_H
#define INC_21F_FLIGHT_PLANNER_ADJLIST_H

#include <iostream>
#include "DSLList.h"

using namespace std;

template <class T>
class AdjList{
public:
    void add_edge(DSLList<T>, T, T, T, T, T);
};
    //insertion/addition of a segment of the adjacency list
template <class T>
void add_edge(DSLList<T> adjacency_list, T from, T to, T cost, T time, T airline){
    adjacency_list[from].push_back(from);
    adjacency_list[to].push_back(to);
    adjacency_list[cost].push_back(cost);
    adjacency_list[time].push_back(time);
    adjacency_list[airline].push_back(airline);
}
#endif //INC_21F_FLIGHT_PLANNER_ADJLIST_H
