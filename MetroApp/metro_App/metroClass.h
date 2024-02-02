#include <iostream>
#include <iomanip> // For setw
#include <string>
#include <vector>
using namespace std;

// Define the Event structure
class Event
{
public:
    string origin;        // Origin station of the transportation route
    string destination;   // Destination station of the transportation route
    double distanceKm;    // Distance between origin and destination in kilometers
    string arrivalTime;   // Time when the transportation route arrives at the destination
    string departureTime; // Time when the transportation route departs from the origin
    string route;         // Route or line identifier of the transportation route
    Event *next;          // Pointer to the next Event in the linked list
};

// Function to display the schedule in tabular format.
void displaySchedule(Event *head)
{
    // Create a pointer 'current' to traverse the linked list starting from the head
    Event *current = head;

    // Display header for the schedule table with setw for column alignment
    cout << left << setw(15) << "Origin" << setw(15) << "Destination"
         << setw(15) << "Distance(km)" << setw(15) << "Arrival Time"
         << setw(15) << "Departure Time" << setw(15) << "Route" << endl;

    // Display a horizontal line as a separator
    cout << string(90, '-') << endl;

    // Traverse the linked list and display each node's information
    while (current != nullptr)
    {
        // Output each attribute of the current node with setw for column alignment
        cout << setw(15) << current->origin << setw(15) << current->destination
             << setw(15) << current->distanceKm << setw(15) << current->arrivalTime
             << setw(15) << current->departureTime << setw(15) << current->route << endl;

        // Move to the next node in the linked list
        current = current->next;
    }
}

// Function to automatically sort the whole events by departure time if the stations happen to change the schedule
void sortScheduleByDepartureTime(Event *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return; // List is empty or has only one element, already sorted
    }

    bool swapped;
    Event *current;
    Event *last = nullptr;

    do
    {
        swapped = false;
        current = head;

        while (current->next != last)
        {
            if (current->departureTime > current->next->departureTime)
            {
                swap(current->origin, current->next->origin);
                swap(current->destination, current->next->destination);
                swap(current->distanceKm, current->next->distanceKm);
                swap(current->arrivalTime, current->next->arrivalTime);
                swap(current->departureTime, current->next->departureTime);
                swap(current->route, current->next->route);

                swapped = true;
            }

            current = current->next;
        }

        last = current;

    } while (swapped);
}

// Function to add a new event to the schedule
void addEvent(Event *&head, const string &origin, const string &destination,
              double distanceKm, const string &arrivalTime, const string &departureTime,
              const string &route)
{
    // Create a new event
    Event *newEvent = new Event;             // Allocate memory for a new Event object
    newEvent->origin = origin;               // Set the origin attribute of the new event
    newEvent->destination = destination;     // Set the destination attribute of the new event
    newEvent->distanceKm = distanceKm;       // Set the distanceKm attribute of the new event
    newEvent->arrivalTime = arrivalTime;     // Set the arrivalTime attribute of the new event
    newEvent->departureTime = departureTime; // Set the departureTime attribute of the new event
    newEvent->route = route;                 // Set the route attribute of the new event
    newEvent->next = nullptr;                // Set the next pointer of the new event to nullptr

    // If the list is empty, make the new event the head
    if (head == nullptr)
    {
        head = newEvent;
    }
    else
    {
        // Otherwise, find the last event and link the new event
        Event *current = head; // Start from the head of the linked list
        while (current->next != nullptr)
        {
            current = current->next; // Move to the next event in the linked list
        }
        current->next = newEvent; // Link the new event to the last event in the linked list
    }
}

// Function to delete the entire schedule and free memory
void deleteSchedule(Event *&head)
{
    // While there are still events in the linked list
    while (head != nullptr)
    {
        // Create a temporary pointer to the current head
        Event *temp = head;

        // Move the head to the next event in the linked list
        head = head->next;

        // Delete the event pointed to by the temporary pointer
        delete temp;
    }
}
