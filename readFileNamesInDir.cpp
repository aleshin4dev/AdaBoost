#include <iostream>
#include "fstream"
#include <vector>
#include <string>
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>

using namespace std;

vector<string> getFileNames() {
	/* директория, в которой находятся изображения для обучения */
	string dir = string("/home/aleshin8sergey/Images/.");
	vector<string> files = vector<string>();
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
	
	return files;
}
