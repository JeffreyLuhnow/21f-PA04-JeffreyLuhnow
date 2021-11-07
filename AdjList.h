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
void add_edge(DSLList<T> adjacency_list[], T u, T v, T x, T y, T z){
    adjacency_list[u].push_back(v);
    adjacency_list[v].push_back(u);
    adjacency_list[x].push_back(x);
    adjacency_list[y].push_back(y);
    adjacency_list[z].push_back(z);
}
#endif //INC_21F_FLIGHT_PLANNER_ADJLIST_H
