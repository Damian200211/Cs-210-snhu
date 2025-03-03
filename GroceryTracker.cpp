#include "GroceryTracker.h"
#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

GroceryTracker::GroceryTracker() {
	// initialization code if needed 
}

GroceryTracker::~GroceryTracker() {
	// cleanup if needed 
}

void GroceryTracker::loadData(const string &filename) {
	ifstream infile(filename);
	if (!infile.is_open()) {
		cerr << "Error opening file: " << filename << endl;
		return;
	}

	string word;
	// read each word from file and update map 
	while (infile >> word) {
		itemFrequency[word]++;
	}
	infile.close();
}

int GroceryTracker::getFrequency(const string& item) {
	if (itemFrequency.find(item) != itemFrequency.end())
		return itemFrequency[item];
	else
		return 0;
}

void GroceryTracker::printFrequencies() {
	cout << "\nItem Frequencies:\n";
	for (const auto& pair : itemFrequency) {
		cout << pair.first << ": " << pair.second << "\n";
	}
}

void GroceryTracker::printHistogram() {
	cout << "\nItem Frequency Histogram\n";
	for (const auto& pair : itemFrequency) {
		cout << pair.first << " ";
		for (int i = 0; i < pair.second; i++) {
			cout << "*";
		}
		cout << "\n";
	}
}

void GroceryTracker::backupData(const string& backupFile) {
	ofstream outfile(backupFile);
	if (!outfile.is_open()) {
		cerr << "Error opening backup file: " << backupFile << endl;
		return;
	}
	for (const auto& pair : itemFrequency) {
		outfile << pair.first << " " << pair.second << "\n";
	}
	outfile.close();
}