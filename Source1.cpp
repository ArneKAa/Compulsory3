#include <iostream>
#include "File.h"
#include "Folder.h"

using namespace std;

int main() {
	Folder root;
	bool alive = true;
	int input;

	while (alive) {
		cout << "Create folder     [1]\nCreate file       [2]\nPrint file info   [3]\nChange file name  [4]\n";
		cout << "List content      [5]\nLocat largest file[6]\n\n";
		cin >> input;

		switch (input) {
			case 1:
				root.createFolder();
				break;

			case 2:
				root.createFile();
				break;

			case 3:	
				root.printFile();
				break;
				
			case 4:
				root.changeFileName();
				break;

			case 5:
				root.listFiles();
				break;

			case 6:
				root.locateLargestFile();
				break;

			default:
				cout << "You did something wrong";
				return 0;
		}
	}
	return 0;

}