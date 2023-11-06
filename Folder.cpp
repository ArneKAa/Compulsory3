#include <iostream>
#include <random>
#include <chrono>
#include <ctime>
#include "Folder.h"

using namespace std;

Folder::Folder() {
	fileQuantity = 0;
	folders = NULL;
}

Folder::Folder(string name)
{
	fileQuantity = 0;
	folders = new Folder[5];
}

Folder Folder::createFolder(string name) {


	return Folder();
}


File Folder::createFile() {
	bool alive;
	srand(time(0));

	if (fileQuantity >= 10) {
		cout << "\nError: Maximum amount of files in folder has been reached.\n";
		return File();
	}
	File file;

	do {
		alive = false;

		cout << "\nFilename: ";
		cin >> file.name;


		for (int i = 0; i < fileQuantity; i++) {
			if (file.name == files[i].name) {
				cout << "\nError: Name is already in use";
				alive = true;
			}
		}

	} while (alive);

	auto start = chrono::system_clock::now();
	auto legacyStart = chrono::system_clock::to_time_t(start);
	char tmBuff[30];
	ctime_s(tmBuff, sizeof(tmBuff), &legacyStart);
	file.date = tmBuff;


	file.size = rand() % 100;

	cout << endl << file.name << " was successfully created.\n\n";
	files[fileQuantity] = file;
	fileQuantity++;
	return file;
}

File Folder::printFile() {
	string print;

	cout << "\nType the name of the file you want to print:\n";
	cin >> print;

	for (int i = 0; i < fileQuantity; i++) {
		if (print == files[i].name) {
			cout << "\n\n" << files[i].name << " has the size of ";
			cout << files[i].size << "MB, and was created " << files[i].date << endl;
			return File();
		}
	}
	cout << "Could not find the file you were looking for.\n\n";
	return File();
}

File Folder::changeFileName() {
	bool alive;
	string input;
	string input2;
	cout << "\n\nChoose the file you want to change then name of: ";
	cin >> input;
	for (int i = 0; i < fileQuantity; i++) {
		if (input == files[i].name) {
			do {
				alive = false;

				cout << "\n\nRename to: ";
				cin >> input2;

				for (int j = 0; j < fileQuantity; j++) {
					if (input2 == files[j].name && input2 != files[i].name) {
						cout << "\nError: name is already in use";
						alive = true;
					}
				}

			} while (alive);

			files[i].name = input2;
			cout << endl << input << " successfully changed name to " << input2 << "\n\n";
			return File();
		}
	}
	cout << "Could not find the file you were looking for.\n\n";
	return File();
}

File Folder::listFiles() {
	for (int i = 0; i < fileQuantity; i++) {
		cout << files[i].name << ": " << files[i].size << "MB | " << files[i].date << endl;
	}
	
	return File();
}

File Folder::locateLargestFile() {
	int largest = 0;
	
	if (fileQuantity = 0) {
		return File();
	}

	for (int i = 0; i < fileQuantity; i++) {
		if (files[i].size >= files[largest].size) {
			largest = i;
		}
	}
	cout << files[largest].name << " is the largest file with the size of " << files[largest].size << "MB\n";
	return File();
}