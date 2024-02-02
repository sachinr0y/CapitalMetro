/*#include <iostream>
#include <iomanip> // For setw
#include <string>
#include "metroClass.h"
using namespace std;

int main()
{
    // Initialize an empty linked list of events
    Event *schedule = nullptr;

    // Add events to the schedule (customize as needed)
    // Loop 1
    addEvent(schedule, "Khaenri'ah", "Liyue", 8, "10:40:00 AM", "10:45:00 AM", "Blue Line");
    addEvent(schedule, "Liyue", "Snezhnaya", 9, "11:30:00 AM", "11:35:00 AM", "Blue Line\n");

    addEvent(schedule, "Snezhnaya", "Liyue", 9, "10:45:00 AM", "10:50:00 AM", "Blue Line");
    addEvent(schedule, "Liyue", "Khaenri'ah", 8, "11:30:00 AM", "11:35:00 AM", "Blue Line\n");

    addEvent(schedule, "Inazuma", "Liyue", 9, "10:45:00 AM", "10:50:00 AM", "Green Line");
    addEvent(schedule, "Liyue", "Celestia", 9, "11:35:00 AM", "11:40:00 AM", "Green Line");
    addEvent(schedule, "Celestia", "Fontaine", 9, "12:25:00 PM", "12:30:00 PM", "Green Line\n");

    addEvent(schedule, "Fontaine", "Celestia", 9, "10:45:00 AM", "10:50:00 AM", "Green Line");
    addEvent(schedule, "Celestia", "Liyue", 9, "11:35:00 AM", "11:40:00 AM", "Green Line");
    addEvent(schedule, "Liyue", "Inazuma", 9, "12:25:00 PM", "12:30:00 PM", "Green Line\n");

    addEvent(schedule, "Sumeru", "Celestia", 12, "11:00:00 AM", "11:05:00 AM", "Purple Line");
    addEvent(schedule, "Celestia", "Mondstadt", 5, "11:30:00 AM", "11:35:00 AM", "Purple Line");
    addEvent(schedule, "Mondstadt", "Khaenri'ah", 10, "12:25:00 PM", "12:30:00 PM", "Purple Line\n");

    addEvent(schedule, "Khaenri'ah", "Mondstadt", 10, "10:50:00 AM", "10:55:00 AM", "Purple Line");
    addEvent(schedule, "Mondstadt", "Celestia", 5, "11:20:00 AM", "11:25:00 AM", "Purple Line");
    addEvent(schedule, "Celestia", "Sumeru", 12, "12:25:00 PM", "12:30:00 PM", "Purple Line\n");

    addEvent(schedule, "Natlan", "Mondstadt", 10, "10:50:00 AM", "10:55:00 AM", "Red Line");
    addEvent(schedule, "Mondstadt", "Liyue", 9, "11:40:00 AM", "11:45:00 AM", "Red Line");
    addEvent(schedule, "Liyue", "Sumeru", 9, "12:30:00 PM", "12:35:00 PM", "Red Line\n");

    addEvent(schedule, "Sumeru", "Liyue", 9, "10:45:00 AM", "10:50:00 AM", "Red Line");
    addEvent(schedule, "Liyue", "Mondstadt", 9, "11:35:00 AM", "11:40:00 AM", "Red Line");
    addEvent(schedule, "Mondstadt", "Natlan", 10, "12:30:00 PM", "12:35:00 PM", "Red Line\n");

    addEvent(schedule, "Fontaine", "Natlan", 14, "11:10:00 AM", "11:15:00 AM", "Orange Line");
    addEvent(schedule, "Natlan", "Khaenri'ah", 18, "12:45:00 PM", "12:50:00 PM", "Orange Line");
    addEvent(schedule, "Khaenri'ah", "Inazuma", 12, "13:50:00 PM", "13:55:00 PM", "Orange Line");
    addEvent(schedule, "Inazuma", "Snezhnaya", 6, "14:25:00 PM", "14:30:00 PM", "Orange Line");
    addEvent(schedule, "Snezhnaya", "Sumeru", 8, "15:10:00 PM", "15:15:00 PM", "Orange Line\n");

    addEvent(schedule, "Sumeru", "Snezhnaya", 8, "10:40:00 AM", "10:45:00 AM", "Orange Line");
    addEvent(schedule, "Snezhnaya", "Inazuma", 6, "11:15:00 AM", "11:20:00 AM", "Orange Line");
    addEvent(schedule, "Inazuma", "Khaenri'ah", 12, "12:20:00 PM", "12:25:00 PM", "Orange Line");
    addEvent(schedule, "Khaenri'ah", "Natlan", 18, "13:55:00 PM", "14:00:00 PM", "Orange Line");
    addEvent(schedule, "Natlan", "Fontaine", 14, "15:10:00 PM", "15:15:00 PM", "Orange Line\n");

    // Loop 2
    addEvent(schedule, "Khaenri'ah", "Liyue", 8, "12:15:00 PM", "12:20:00 PM", "Blue Line");
    addEvent(schedule, "Liyue", "Snezhnaya", 9, "13:05:00 PM", "13:10:00 PM", "Blue Line\n");

    addEvent(schedule, "Snezhnaya", "Liyue", 9, "12:20:00 PM", "12:25:00 PM", "Blue Line");
    addEvent(schedule, "Liyue", "Khaenri'ah", 8, "13:05:00 AM", "13:10:00 AM", "Blue Line\n");

    addEvent(schedule, "Inazuma", "Liyue", 9, "13:15:00 PM", "13:20:00 PM", "Green Line");
    addEvent(schedule, "Liyue", "Celestia", 9, "14:05:00 PM", "14:10:00 PM", "Green Line");
    addEvent(schedule, "Celestia", "Fontaine", 9, "14:55:00 PM", "15:00:00 PM", "Green Line\n");

    addEvent(schedule, "Fontaine", "Celestia", 9, "13:15:00 PM", "13:20:00 PM", "Green Line");
    addEvent(schedule, "Celestia", "Liyue", 9, "14:05:00 PM", "14:10:00 PM", "Green Line");
    addEvent(schedule, "Liyue", "Inazuma", 9, "14:55:00 PM", "15:00:00 PM", "Green Line\n");

    addEvent(schedule, "Sumeru", "Celestia", 12, "13:30:00 PM", "13:35:00 PM", "Purple Line");
    addEvent(schedule, "Celestia", "Mondstadt", 5, "14:00:00 AM", "14:05:00 AM", "Purple Line");
    addEvent(schedule, "Mondstadt", "Khaenri'ah", 10, "14:55:00 PM", "15:00:00 PM", "Purple Line\n");

    addEvent(schedule, "Khaenri'ah", "Mondstadt", 10, "13:20:00 PM", "13:25:00 PM", "Purple Line");
    addEvent(schedule, "Mondstadt", "Celestia", 5, "13:50:00 PM", "13:55:00 PM", "Purple Line");
    addEvent(schedule, "Celestia", "Sumeru", 12, "14:55:00 PM", "15:00:00 PM", "Purple Line\n");

    addEvent(schedule, "Natlan", "Mondstadt", 10, "13:25:00 PM", "13:30:00 PM", "Red Line");
    addEvent(schedule, "Mondstadt", "Liyue", 9, "14:15:00 PM", "14:20:00 PM", "Red Line");
    addEvent(schedule, "Liyue", "Sumeru", 9, "15:05:00 PM", "15:10:00 PM", "Red Line\n");

    addEvent(schedule, "Sumeru", "Liyue", 9, "13:20:00 PM", "13:25:00 PM", "Red Line");
    addEvent(schedule, "Liyue", "Mondstadt", 9, "14:10:00 AM", "14:15:00 AM", "Red Line");
    addEvent(schedule, "Mondstadt", "Natlan", 10, "15:05:00 PM", "15:10:00 PM", "Red Line\n");

    addEvent(schedule, "Fontaine", "Natlan", 14, "16:25:00 PM", "16:30:00 PM", "Orange Line");
    addEvent(schedule, "Natlan", "Khaenri'ah", 18, "18:00:00 PM", "18:05:00 PM", "Orange Line");
    addEvent(schedule, "Khaenri'ah", "Inazuma", 12, "19:05:00 PM", "19:10:00 PM", "Orange Line");
    addEvent(schedule, "Inazuma", "Snezhnaya", 6, "19:40:00 PM", "19:45:00 PM", "Orange Line");
    addEvent(schedule, "Snezhnaya", "Sumeru", 8, "20:25:00 PM", "20:30:00 PM", "Orange Line\n");

    addEvent(schedule, "Sumeru", "Snezhnaya", 8, "15:55:00 PM", "16:00:00 PM", "Orange Line");
    addEvent(schedule, "Snezhnaya", "Inazuma", 6, "16:30:00 PM", "16:35:00 PM", "Orange Line");
    addEvent(schedule, "Inazuma", "Khaenri'ah", 12, "17:35:00 PM", "17:40:00 PM", "Orange Line");
    addEvent(schedule, "Khaenri'ah", "Natlan", 18, "19:10:00 PM", "19:15:00 PM", "Orange Line");
    addEvent(schedule, "Natlan", "Fontaine", 14, "20:25:00 PM", "20:30:00 PM", "Orange Line\n");

    // Display the schedule
    cout << "Schedule:" << endl;
    displaySchedule(schedule);

    // Delete the schedule and free memory
    deleteSchedule(schedule);

    return 0;
}
*/
