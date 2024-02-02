#include <iostream>
#include <iomanip> // For setw
#include <string>
#include "metroClass.h"
#include <vector>
#include <queue>
#include <limits>
#include "Graph.h"
using namespace std;

int main()
{
    // Initialize an empty linked list of events
    Event *schedule = nullptr;

    // Loop 1
    addEvent(schedule, "Rajiv Chowk", "Kashmiri Gate", 8, "10:40:00 AM", "10:45:00 AM", "Blue Line");
    addEvent(schedule, "Kashmiri Gate", "Dwarka", 9, "11:30:00 AM", "11:35:00 AM", "Blue Line\n");

    addEvent(schedule, "Dwarka", "Karol Bagh", 9, "10:45:00 AM", "10:50:00 AM", "Blue Line");
    addEvent(schedule, "Karol Bagh", "Akshardham", 8, "11:30:00 AM", "11:35:00 AM", "Blue Line\n");


    //CODES FOR THE SCHEDULE ENDS HERE//
    

    //CODES FOR THE PATH FINDER STARTS HERE//

    // Number of Vertices Definition
    int vertices = 9;
    Graph graph(vertices);

    // Add edges with distances
    graph.addEdge(0, 1, 8); // Rajiv Chowk to Kashmiri Gate, distance: 8
    graph.addEdge(0, 3, 12);
    graph.addEdge(0, 7, 10);
    graph.addEdge(0, 8, 18);

    graph.addEdge(1, 2, 9);
    graph.addEdge(1, 4, 9);
    graph.addEdge(1, 7, 9);
    graph.addEdge(1, 3, 12);
    graph.addEdge(1, 6, 9);

    graph.addEdge(2, 3, 6);
    graph.addEdge(2, 6, 6);

    graph.addEdge(4, 5, 9);
    graph.addEdge(4, 6, 12);
    graph.addEdge(4, 7, 5);

    graph.addEdge(5, 8, 14);
    graph.addEdge(7, 8, 10);

    //=============================================================================================================================//
    //                                  CODES FOR THE PATH FINDER ENDS HERE                                                        //
    //=============================================================================================================================//

    cout << " ===================================================";
    cout << "\n  * *   * *   ******   *******   *****    *******   ";
    cout << "\n  *  * *  *   *           *      *    *   *     *   ";
    cout << "\n  *   *   *   ******      *      *****    *     *   ";
    cout << "\n  *       *   *           *      *  *     *     *   ";
    cout << "\n  *       *   ******      *      *   *    *******   ";
    cout << "\n ==================================================";
    cout << "\n\n";

    cout << "Welcome to our Metro app!";

    while (1)
    {
        int action;

        cout << "\n[1] View Train Schedule \n[2] Find Fastest Route\n\nInsert number for action: ";
        cin >> action;

        if (action == 1)
        {
            // Display the schedule
            cout << "Schedule:" << endl;
            sortScheduleByDepartureTime(schedule);
            displaySchedule(schedule);

            // Delete the schedule and free memory
            deleteSchedule(schedule);
        }
        else if (action == 2)
        {
            // Prompting user into putting their location
            int startNode;
            cout << "\n||==============================================||";
            cout << "\n||0||Rajiv Chowk                                 ||";
            cout << "\n||1||Kashmiri Gate                               ||";
            cout << "\n||2||Dwarka                                      ||";
            cout << "\n||3||Karol Bagh                                  ||";
            cout << "\n||4||Akshardham                                  ||";
            cout << "\n||5||Lajpat Nagar                                ||";
            cout << "\n||6||Janakpuri                                   ||";
            cout << "\n||7||Inderlok                                    ||";
            cout << "\n||8||Vaishali                                    ||";
            cout << "\n||==============================================||\n";

            cout << "I'm at station number: ";
            cin >> startNode;

            // Choose the starting node
            vector<int> parent = graph.getShortestPathTree(startNode);

            // Prompting user into putting their destination
            int destination;
            cout << "I'm going to station number: ";
            cin >> destination;

            // printing the result
            string path = graph.getPath(startNode, destination, parent);
            cout << "Shortest Path from station " << startNode << " to station " << destination << ": " << path << endl;

            return 0;
        }
        else
        {
            cout << "\nInput unrecognized";
            continue;
        }
    }

    return 0;
}

