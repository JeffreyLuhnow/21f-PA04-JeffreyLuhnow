//
// Created by MARK FONTENOT on 9/14/21.
//

/**
 * This file contains some simple tests.
 *
 * DO NOT add the #define CATCH_CONFIG_RUNNER to this file.
 * It is already in catch_setup.cpp
 *
 * Note that you can have more than one cpp file with tests in them.
 * For example, you could have a test file for your DSString and a
 * separate one for your DSVector.
 */

#include "catch.hpp"
#include "DSLList.h"
#include "DSStack.h"
#include "AdjList.h"


TEST_CASE("Testing Tests", "[multiplication]") {
    REQUIRE((2 * 2) == 4);
    REQUIRE((1 * 5) == 5);
}
//TESTING DSLLIST

TEST_CASE("Testing DSLList empty function"){
    DSLList<int> *ints = new DSLList<int>();
    REQUIRE(ints->isEmpty() == true);
}

TEST_CASE("Testing DSLList insert functions"){
    DSLList<int> *list = new DSLList<int>();
    int x = 4;
    int y = 5;
    int z = 6;
    list->insertHead(x);
    list->insertTail(y);
    list->insertTail(z);

    REQUIRE(list->sizeOfList() == 3);
}

//TESTING DSSTACK

TEST_CASE("Testing DSStack push (and peek) function"){
    DSStack<int> *intList;
    intList->push(0);
    intList->push(1);
    intList->push(2);

    REQUIRE(intList->isEmpty() == false);
    REQUIRE(intList->getSize() == 3);
    REQUIRE(intList->peek() == 2);

}

TEST_CASE("Testing DSStack pop function"){
    DSStack<int> *intList1;
    intList1->push(0);
    intList1->push(1);
    intList1->push(2);

    intList1->pop();
    intList1->pop();
    intList1->pop();

    REQUIRE(intList1->isEmpty() == true);
    REQUIRE(intList1->getSize() == 0);
}


TEST_CASE("testing Adj List"){
    DSLList<T> *testList;
    int x = 0;
    int y = 1;
    AdjList obj;
    add_edge(testList, x, y);
    REQUIRE(testList->getSize() != 0);
    REQUIRE(testList->isEmpty() != true);
}