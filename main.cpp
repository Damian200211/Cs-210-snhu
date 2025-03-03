#include <iostream>
#include <limits>
#include <string>
#include "GroceryTracker.h"

using namespace std;

// dynamic memory allocation and cleanup
void demoDynamicArray() {
	cout << "\nDemonstrating dynamic memory allocation and proper cleanup\n";
	int arraySize = 10;
	int* grades = new int[arraySize];

	for (int i = 0; i < arraySize; i++) {
		grades[i] = i * 10;
	}
	
	// Display the dynamic array 
	cout << "Grades array: ";
	for (int i = 0; i < arraySize; i++) {
		cout << grades[i] << " ";
	}
	cout << "\n";

	// clean up the allocated memory
	delete[] grades;
}

int main() {
	GroceryTracker tracker;
	// inputfiles
	const string inputFileName = "InputFiles.txt";
	const string backupFileName = "frequency.dat";

	// load data from the input files and creat a backup
	tracker.loadData(inputFileName);
	tracker.backupData(backupFileName);

	int choice;
	string item;
	bool exitProgram = false;

	// main menu loop
	while (!exitProgram) {
		cout << "\nCorner Grocer Item Tracking Program Menu:\n";
		cout << "1. Look up frequency of an item\n";
		cout << "2. Display all item frequencies\n";
		cout << "3. Display histogram of item frequencies\n";
		cout << "4. Demonstrate pointer usage\n";
		cout << "5. Exit\n";
		cout << "Enter your choice (1-5): ";
		cin >> choice;

		// validate user input
		if (cin.fail() || choice < 1 || choice > 5) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid input. Please enter a number betweeen 1 and 5.\n";
			continue;
		}

		// process menu selection
		switch (choice) {
			case 1:
				cout << "Enter the item to look up: ";
				cin >> item;
				cout << "Frequency of '" << item << "': " << tracker.getFrequency(item) << "\n";
				break;
			case 2:
				tracker.printFrequencies();
				break;
			case 3:
				tracker.printHistogram();
				break;
			case 4:
				demoDynamicArray();
				break;
			case 5:
				cout << "Exiting program...\n";
				exitProgram = true;
				break;
			default:
				cout << "Invalid option. Please try again.\n";
				break;

		}
	}
	return 0;
}