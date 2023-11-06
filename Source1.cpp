#include <iostream>
#include "File.h"
#include "Folder.h"

using namespace std;

int main() {
	Folder root("root", "");
	Folder* currentFolder = &root;
	bool alive = true;
	int input;

	while (alive) {
		currentFolder->printRecursive(currentFolder->parent);
		cout << "\nCreate folder      [1]\nCreate file        [2]\nChange file name   [3]\nChange folder name [4]";
		cout << "\nList content       [5]\nLocate largest file[6]\nOpen folder        [7]\nGo back            [8]\n\n";
		cin >> input;

		switch (input) {
			case 1:
				currentFolder->createFolder();
				break;

			case 2:
				currentFolder->createFile();
				break;

			case 3:	
				currentFolder->changeFileName();
				break;
				
			case 4:
				currentFolder->changeFolderName();
				break;

			case 5:
				currentFolder->listContent();
				break;

			case 6:
				currentFolder->locateLargestFile();
				break;

			case 7:
				currentFolder = currentFolder->changeFolder();
				break;

			case 8:
				currentFolder = currentFolder->parent;
				break;

			default:
				cout << "Something went wrong";
				return 0;
		}
	}
	return 0;

}