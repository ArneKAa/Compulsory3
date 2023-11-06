#pragma once
#include "File.h"
class Folder
{
private:
	File files[10];
	Folder* folders;
	int fileQuantity;
public:
	Folder();
	Folder(string name);
	Folder createFolder(string name);
	File createFile();
	File printFile();
	File changeFileName();
	File listFiles();
	File locateLargestFile();
};

