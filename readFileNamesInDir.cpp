#include <iostream>
#include "fstream"
#include <vector>
#include <string>
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>

using namespace std;

int getFileNames() {
	/* директория, в которой находятся изображения для обучения */
	string dir = string("/home/aleshin8sergey/Images/.");
	vector<string> files = vector<string>();
	DIR *dp;
	struct dirent *dirp;

	if((dp  = opendir(dir.c_str())) == NULL) {
		cout << "Error(" << errno << ") opening " << dir << endl;
		return errno;
	}

	while ((dirp = readdir(dp)) != NULL)
		files.push_back(string(dirp->d_name));
	closedir(dp);

	/* файл в который пишем имена изображений */
	fstream ff("/home/aleshin8sergey/Workspace/Coursework/AdaBoost/Names.txt");
	for (int i = 0; i < files.size(); i++) {
		if((files[i] != ".") && (files[i] != "..")) ff << files[i] << endl;
	}
	ff.close();
	
	return 0;
}
