// Robotics_project_tracker.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <windows.h>
using namespace std;

// Display the welcome messagec
void displayBanner()
{
    cout << "=================================" << endl;
    cout << " Welcome to the Robotics Tracker!" << endl;
    cout << "=================================" << endl;
    cout << endl;
}
// Calculate the robot's progress
double calculateProgress(int finishedParts, int totalParts)
{
    return finishedParts * 100.0 / totalParts;
}
void getRobotName(string& name)
{
    cout << "What is your robot's name? ";
    getline(cin, name);
}
// Ask how many parts the robot has NEW FUNCTION
int getTotalParts()
{
	int totalParts;
    cout << "How many parts does your robot have? ";
    cin >> totalParts;

    while (cin.fail() || totalParts <= 0)
    {
        cin.clear();
        cin.ignore(1000, '\n');

        cout << "Invalid input. Enter a number greater than 0: ";
        cin >> totalParts;
    }
    return totalParts;
}
int getFinishedParts(int totalParts)
{
    int finishedParts;
    cout << "How many parts are finished? ";
    cin >> finishedParts;


    while (cin.fail() || finishedParts < 0 || finishedParts > totalParts)
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid input. Try again:  ";
        cin >> finishedParts;
    }
    return finishedParts;
}
double getHoursWorked()
{
    double hoursWorked = 0.0;
    cout << "How many hours have you worked on your robot? ";
    cin >> hoursWorked;
    while (cin.fail() || hoursWorked < 0)
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid input. Enter a valid number of hours: ";
        cin >> hoursWorked;
    }
    return hoursWorked;
}
void displayMenu()
{
    cout << endl;
    cout << "Robotics Progress Tracker Menu" << endl;
    cout << "1. View Robot Progress" << endl;
    cout << "2. Check Robot Readiness" << endl;
    cout << "3. Get Building Advice" << endl;
}
void saveReport(const string& robotName, int totalParts, int finishedParts, int partsLeft, double hoursWorked, double percentageCompleted)
{
	ofstream report("report.txt");
	report << fixed << setprecision(1);
	report << "Robotics Build Tracker" << endl;
	report << "----------------------------------" << endl;
	report << left << setw(24) << "Robot Name" << robotName << endl;
	report << left << setw(24) << "Total Parts" << totalParts << endl;
	report << left << setw(24) << "Finished Parts" << finishedParts << endl;
	report << left << setw(24) << "Parts Left" << partsLeft << endl;
	report << left << setw(24) << "Hours Worked" << hoursWorked << endl;
	report << left << setw(24) << "Completion Percentage"
		<< percentageCompleted << "%" << endl;
	report.close();
}
void changeConsoleColor()
{
	HANDLE Console = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(Console, 13);
}
int main()
{
	changeConsoleColor();

    displayBanner();


    // Variables for the robot
    string robotName;
    int totalParts;
    int finishedParts;
    int partsLeft;
    double hoursWorked = 0.0;

    // Ask for the robot's name

    getRobotName(robotName);


    // Ask how many parts the robot has
	totalParts = getTotalParts();

    // Ask how many parts are finished
    finishedParts = getFinishedParts(totalParts);
    // Ask how many hours were worked
	hoursWorked = getHoursWorked();
    // Calculate how many parts are left 
    partsLeft = totalParts - finishedParts;

    // calculate percentage of parts complete
	double percentageCompleted = calculateProgress(finishedParts, totalParts);

    // Display five robot building progress steps
    cout << endl;
    cout << "Robot Building Checklist" << endl;

    for (int step = 1; step <= 5; step++)
    {
        cout << "Building step " << step << " of 5" << endl;
    }

    // Ask the user if they want to use the menu again
    char repeatChoice;
	
    do
    {
        // Menu for the Robotics Progress Tracker
		int menuChoice;

        displayMenu();

        cout << "Enter your choice (1-3): ";
        cin >> menuChoice;

        while (cin.fail() || menuChoice < 1 || menuChoice > 3)
        {
            cin.clear();
            cin.ignore(1000, '\n');

            cout << "Invalid choice. Please enter 1, 2, or 3: ";
            cin >> menuChoice;
        }


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
        continue;
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


        // robots progress table 
        cout << fixed << setprecision(1);
        cout << endl;
        cout << "Robot Progress Table" << endl;
        cout << "----------------------------------" << endl;
        cout << left << setw(24) << "Robot Name" << robotName << endl;
        cout << left << setw(24) << "Total Parts" << totalParts << endl;
        cout << left << setw(24) << "Finished Parts" << finishedParts << endl;
        cout << left << setw(24) << "Parts Left" << partsLeft << endl;
        cout << left << setw(24) << "Hours Worked" << hoursWorked << endl;
        cout << left << setw(24) << "Completion Percentage" << percentageCompleted << "%" << endl;

        // Robotics report file
        saveReport(robotName, totalParts, finishedParts, partsLeft, hoursWorked, percentageCompleted);
        cout << "Your robot's progress has been saved." << endl;
        cout << endl;
    }
    // ask whether user want to use menu again
    cout << "Would you like to use the menu again? (y/n): ";
    cin >> repeatChoice;

    } while (repeatChoice == 'y' || repeatChoice == 'Y');

    return 0;
}