// Robotics_project_tracker.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;

int main()
{
    // Welcome message 
    cout << "=================================" << endl;
    cout << " Welcome to the Robotics Tracker!" << endl;
    cout << "=================================" << endl;
    cout << endl;

    // Variables for the robot
    string robotName;
    int totalParts;
    int finishedParts;
    int partsLeft;
    double hoursWorked;
    // Ask for the robot's name
    cout << "What is your robot's name? ";
    cin >> robotName;

    // Ask how many parts the robot has
    cout << "How many parts does your robot have? ";
    cin >> totalParts;

    // Check the total parts input
    if (cin.fail() || totalParts <= 0)
    {
        cout << "Invalid input. Enter a number greater than 0." << endl;
        return 1;
    }

    // Ask how many parts are finished
    cout << "How many parts are finished? ";
    cin >> finishedParts;

    // Check the finished parts input
    if (cin.fail() || finishedParts < 0 || finishedParts > totalParts)
    {
        cout << "Invalid input. Check your finished parts." << endl;
        return 1;
    }

    // Ask how many hours were worked
    cout << "How many hours have you worked on your robot? ";
    cin >> hoursWorked;

    // Check the hours input
    if (cin.fail() || hoursWorked < 0)
    {
        cout << "Invalid input. Enter a valid number of hours." << endl;
        return 1;
    }


    // Calculate how many parts are left 
    partsLeft = totalParts - finishedParts;

    // calculate percentage of parts completed
    double percentageCompleted = finishedParts * 100.0 / totalParts;

    // Menu for the Robotics Progress Tracker
    int menuChoice;

    cout << endl;
    cout << "Robotics Progress Tracker Menu" << endl;
    cout << "1. View Robot Progress" << endl;
    cout << "2. Check Robot Readiness" << endl;
    cout << "3. Get Building Advice" << endl;

    cout << "Enter your choice (1-3): ";
    cin >> menuChoice;


    // Use the menu choice to decide what to do
    switch (menuChoice)
    {
    case 1:
        cout << "Here is your robot's progress." << endl;
        break;

    case 2:
        // Check if the robot is ready

        if (percentageCompleted >= 75 && hoursWorked >= 5)
        {
            cout << "Your robot is almost ready!" << endl;
        }
        else
        {
            cout << "Your robot still needs more work." << endl;
        }
        break;

    case 3:
        // Give advice based on the robot's progress
        if (percentageCompleted < 50 || hoursWorked < 3)
        {
            cout << "Your robot needs more building time." << endl;
        }
        else
        {
            cout << "Keep up the good work on your robot!" << endl;
        }
        break;
    default:
        cout << "Invalid choice. Please enter 1, 2, or 3." << endl;
    }

    if (menuChoice == 1)
    {

        // Display the robot's progress
        cout << endl;
        cout << "Robotics Build Tracker" << endl;
        cout << "Your robot " << robotName << " has "
            << totalParts << " parts." << endl;
        cout << finishedParts << " parts are finished and "
            << partsLeft << " parts still need to be completed."
            << endl;
        cout << "Completion percentage: " << percentageCompleted << "%" << endl;
    }

    // robots progress table 
    cout << endl;
    cout << "Robot Progress Table" << endl;
    cout << "----------------------------------" << endl;
    cout << left << setw(24) << "Robot Name" << robotName << endl;
    cout << left << setw(24) << "Total Parts" << totalParts << endl;
    cout << left << setw(24) << "Finished Parts" << finishedParts << endl;
    cout << left << setw(24) << "Parts Left" << partsLeft << endl;
    cout << left << setw(24) << "Hours Worked" << hoursWorked << endl;

    cout << fixed << setprecision(1);
    cout << left << setw(24) << "Completion Percentage" << percentageCompleted << "%" << endl;

    // Robotics report file
    ofstream report("report.txt");
    report << "Robotics Build Tracker" << endl;
    report << "----------------------------------" << endl;

    report << left << setw(24) << "Robot Name" << robotName << endl;
    report << left << setw(24) << "Total Parts" << totalParts << endl;
    report << left << setw(24) << "Finished Parts" << finishedParts << endl;
    report << left << setw(24) << "Parts Left" << partsLeft << endl;
    report << left << setw(24) << "Hours Worked" << hoursWorked << endl;

    report << fixed << setprecision(1);
    report << left << setw(24) << "Completion Percentage"
        << percentageCompleted << "%" << endl;

    report.close();
    cout << "Your robot's progress has been saved." << endl;
    return 0;
}