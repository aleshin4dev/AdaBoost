#include <iostream>
#include "fstream"
#include <sstream>
#include <vector>
#include <string>
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>

using namespace std;

vector<string> getFileNames() {
	int imFace;
	vector<string> files = vector<string>();
	/*
	* изображения с лицами и без хранятся
	* в разных папках
	*/
	for (int i=1; i>=0; i--) {
		ostringstream anOut;
		anOut << "/home/aleshin8sergey/Workspace/Coursework/Images/" << i << "/.";
		string dir = string(anOut.str());
		DIR *dp;
		struct dirent *dirp;

		if((dp  = opendir(dir.c_str())) == NULL) {
			cout << "Error(" << errno << ") opening " << dir << endl;
			files[0] = errno;
			return files;
		}

		while ((dirp = readdir(dp)) != NULL)
			files.push_back(string(dirp->d_name));
		closedir(dp);
		if (i == 1) imFace = files.size(); // количество изображений с лицом + директории "." и ".."
	}
	stringstream imFaceStr;
	imFaceStr << imFace;
	files.push_back(imFaceStr.str()); // последний элемент вектора - число изображений с лицом
	return files;
}
