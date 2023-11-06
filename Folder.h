#pragma once
#include "File.h"
class Folder
{
private:
	File files[10];
	Folder* folders;
	int fileQuantity;
	int folderQuantity;
	string name;
	string date;
public:
	Folder();
	Folder(string folderName, string folderDate);
	int getSize();
	Folder changeFolderName();
	Folder* parent;
	Folder printRecursive(Folder* folder);
	Folder createFolder();
	Folder* changeFolder();
	File createFile();
	File changeFileName();
	File listContent();
	File locateLargestFile();
};

