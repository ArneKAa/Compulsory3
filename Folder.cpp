#include <iostream>
#include <random>
#include <chrono>
#include <ctime>
#include "Folder.h"

using namespace std;


Folder::Folder() {
	parent = this;
	fileQuantity = 0;
	folders = NULL;
	folderQuantity = 0;
}

Folder::Folder(string folderName, string folderDate) {
	parent = this;
	folderQuantity = 0;
	fileQuantity = 0;
	folders = new Folder[5];
	name = folderName;
	date = folderDate;
}

int Folder::getSize() {
	int sizeSum = 0;
	for (int i = 0; i < fileQuantity; i++) {
		sizeSum += files[i].size;
	}
	for (int i = 0; i < folderQuantity; i++) {
		sizeSum += folders[i].getSize();
	}
	return sizeSum;
}

Folder Folder::changeFolderName(){
	bool alive;
	string input;
	string input2;
	cout << "\n\nChoose the folder you want to change then name of: ";
	cin >> input;
	for (int i = 0; i < folderQuantity; i++) {
		if (input == folders[i].name) {
			do {
				alive = false;
				cout << "\n\nRename to: ";
				cin >> input2;
				for (int j = 0; j < folderQuantity; j++) {
					if (input2 == folders[j].name && input2 != folders[i].name) {
						cout << "\nError: name is already in use";
						alive = true;
					}
				}
			} while (alive);
			folders[i].name = input2;
			cout << endl << input << " successfully changed name to " << input2 << "\n\n";
			return Folder();
		}
	}
	cout << "Could not find the file you were looking for.\n\n";
	return Folder();
}

Folder Folder::printRecursive(Folder* folder)
{
	if (parent != this) {
		folder->printRecursive(folder->parent);
	}
	cout << "\\" << name;
	return Folder();
}

Folder Folder::createFolder() {
	if (folderQuantity >= 5) {
		cout << "\nError: Maximum amount of folders in folder has been reached.\n";
		return Folder();
	}

	string folderName;

	cout << "Folder name: ";

	cin >> folderName;

	cout << endl << folderName << " was successfully created.\n\n";

	auto start = chrono::system_clock::now();
	auto legacyStart = chrono::system_clock::to_time_t(start);
	char tmBuff[30];
	ctime_s(tmBuff, sizeof(tmBuff), &legacyStart);

	Folder folder(folderName, tmBuff);
	
	folder.parent = this;


	folders[folderQuantity] = folder;
	folderQuantity++;

	return folder;
}

Folder* Folder::changeFolder()
{
	string input;
	cout << "Choose folder:";
	cin >> input;
	for (int i = 0; i < folderQuantity; i++) {
		if (input == folders[i].name) {
			return &folders[i];
		}
	}
	return this;
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

//File Folder::printFile() {
//	string print;
//
//	cout << "\nType the name of the file you want to print:\n";
//	cin >> print;
//
//	for (int i = 0; i < fileQuantity; i++) {
//		if (print == files[i].name) {
//			cout << "\n\n" << files[i].name << " has the size of ";
//			cout << files[i].size << "MB, and was created " << files[i].date << endl;
//			return File();
//		}
//	}
//	cout << "Could not find the file you were looking for.\n\n";
//	return File();
//}

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

File Folder::listContent() {
	for (int i = 0; i < folderQuantity; i++) {
		cout << "-" << folders[i].name << ": " << folders[i].getSize() << "MB | " << folders[i].date << endl;
	}
	for (int i = 0; i < fileQuantity; i++) {
		cout << files[i].name << ": " << files[i].size << "MB | " << files[i].date << endl;
	}
	
	return File();
}

File Folder::locateLargestFile() {
	int largest = 0;
	
	if (fileQuantity == 0) {
		return File();
	}

	for (int i = 0; i < fileQuantity; i++) {
		if (files[i].size > files[largest].size) {
			largest = i;
		}
	}
	cout << files[largest].name << " is the largest file with the size of " << files[largest].size << "MB\n";
	return File();
}