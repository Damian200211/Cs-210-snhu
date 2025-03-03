#ifndef GROCERYTRACKER_H
#define GROCERYTRACKER_H

#include <string>
#include <map>
using namespace std;

class GroceryTracker {
private:
	//map to store items and their corresponding frequency counts
	map<string, int> itemFrequency;

public:
	// constructor & destructor
	GroceryTracker();
	~GroceryTracker();

	// loads data from file and updates map
	void loadData(const string& filename);

	// returns frequency count for athe item 
	int getFrequency(const string& item);

	// prints all items with frequency 
	void printFrequencies();

	// prints a text-based histogram of item frequencies
	void printHistogram();

	// creats a backup file 
	void backupData(const string& backupFile);
};

#endif
