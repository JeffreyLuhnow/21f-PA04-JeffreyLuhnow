/**
 * Fall 2021 PA 04 - Flight Planner Template Repo.
 * Based on PA 02 Template repo
 */

#include <iostream>
#include <fstream>
#include <string>
#include "DSLList.h"
#include "DSStack.h"
#include "DSVector.h"
#include "AdjList.h"
#include "flights.h"

/**
 * catch_setup.h and catch_setup.cpp contain the #define directive for
 * the CATCH2 framework.  You can see in main below how I'm calling the
 * runCatchTests() function which is declared in this header.
 *
 * On average, this should reduce the build time for your project on your local
 * machine.
 */
#include "catch_setup.h"
#include <iostream>
#include "DSLList.h"

using namespace std;

int main(int argc, char** argv) {
    DSVector<int> flightNums;
    DSVector<string> itineraryNums;
    DSVector<string> cities;
    DSVector<string> times;
    DSVector<string> costs;
                                                            //CATCH TESTS
    if(argc == 1) {
        runCatchTests();
    }
    else {                                                 //ACTUAL PROJECT
        std::ifstream myfile;
        myfile.open(argv[1]);

        DSStack<string> *flightPath;
        DSLList<string> flightInfo;
        AdjList<DSLList<string>> itineraries;
        DSLList<DSLList<string>> itineraryList;
        DSVector<string> airlines;

        int requestNum = 0;
        string sequentialLine;
        string line;

        //INPUT FILE #1 ____________________________________________________________________


        if(myfile.is_open()){
            getline(myfile, line, '\n');
            int flightNum = stoi(line);

                                                                //ACQUIRING INFORMATION FROM THE INPUT FILE 1
            for(int i = 0; i < flightNum; i++){
                getline(myfile, sequentialLine, '\n');
                string delim = " ";
                char delim2 = '\n';
                string from = sequentialLine.substr(0, sequentialLine.find(delim));
                string to = sequentialLine.substr(from.length() + 1, sequentialLine.find(delim));
                string cost = sequentialLine.substr((from.length() + to.length() + 2), sequentialLine.find(delim));
                string time = sequentialLine.substr((from.length() + to.length() + cost.length() + 3), sequentialLine.find(delim));
                string airline = sequentialLine.substr((from.length() + to.length() + time.length() + cost.length() + 4), sequentialLine.find(delim2));
                airlines.push_back(airline);
                times.push_back(time);
                costs.push_back(cost);
                    //SAVING INFORMATION INTO A STACK AND THEN ADJACENCY LIST
                for(int i = 0; i < flightNum; i++){ //performs the following steps X amount of times (x = number on the input file with amount of flights)
                    flightPath->push(from); //fill stack with info
                    flightPath->push(to);    //fill stack with info
                    flightPath->clear();           //clear stack for next use
                    itineraries.add_edge(itineraryList, from, to, cost, time, airline); //DSLList of DSLLists, one DSLList is given such properties
                }
            }
            myfile.close();             //CLOSING FILE


            // INPUT FILE #2 ____________________________________________________________


            std::ifstream file2(argv[2]);           //opening of the itinerary request file
            DSVector<string> cities;
            DSVector<string> dests;
            DSVector<string> TCs;
            string line1;
            string sequentialLine1;
            string delim3 = " ";
            char delim4 = '\n';
            if(file2.is_open()){
                getline(file2, line1, '\n'); //saves first line (number of itis requested)
                requestNum = stoi(line);
                for(int i = 0; i < requestNum; i++){    //performs task for as many times as the num of requests
                    getline(file2, sequentialLine1, '\n');
                    string requestStart = sequentialLine1.substr(0, sequentialLine1.find(delim3));
                    string requestEnd = sequentialLine1.substr(requestStart.length() + 1, sequentialLine1.find(delim3));
                    string TC = sequentialLine1.substr(requestStart.length() + requestEnd.length() + 2, sequentialLine.find(delim4));
                    cities.push_back(requestStart);
                    dests.push_back(requestEnd);
                    TCs.push_back(TC);
                }
            }
            file2.close();

            //OUTPUT FILE _____________________________________

                                        //printing the information to the output file
            ofstream o(argv[3]);
            for(int i = 0; i < requestNum; i++){
                int count = i;
                if(TCs[i] == "T"){
                    o << "Flight " << count << ": " << cities[i] << ", " << dests[i] << "(Time)" << endl;
                    for(int k = 0; k < 3; k ++){
                        o << "  Itinerary " << i << ": " << endl;
                        o << "      " << cities[i] << "->" << dests[i] << " (" << airlines[i] << ")" << endl;
                        o << "      Totals for Itinerary " << i << ": Time: " << times[i] << " Cost: " << costs[i] << endl;
                    }
                }
            }
            o << "" << endl;
            o.close();
        }
        return 0;
    }
}