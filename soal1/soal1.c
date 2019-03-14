#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <syslog.h>
#include <string.h>

//Directory Library
#include <dirent.h>

int main() {
	pid_t pid, sid;
	
	pid = fork();

	if(pid < 0) {
		exit(EXIT_FAILURE);
	}

	if(pid > 0) {
		exit(EXIT_SUCCESS);
	}

	umask(0);

	sid = setsid();

	if(sid < 0) {
		exit(EXIT_FAILURE);
	}

	if((chdir("/home/dejahvoe/Sisop/FolderShift2/soal1")) < 0) {
		exit(EXIT_FAILURE);
	}

	close(STDIN_FILENO);
	close(STDOUT_FILENO);
	close(STDERR_FILENO);

	while(1) {

	struct dirent *directoryentry;
	DIR *directory = opendir(".");

	if(directory == NULL) {
		printf("Could not open current directory");
		//return 0;
	}

	while ((directoryentry = readdir(directory)) != NULL) {
		//Iterasi seluruh file
		char *filename = directoryentry->d_name;
		int length = strlen(filename);

		//Ignore the file
		if(length - 4 < 0) {
			continue;
		}
		
		//Mark file PNG
		char target[5] = ".png";
		int x, y=0, same=1;
		for(x = length - 4; x < length; x++) {
			if(filename[x] != target[y]) {
				same = 0;
				break;
			}
			y++;
		}

		//CHECK
//		printf("%s\n", filename);
//		printf("%d\n", same);

		if(same == 1) {
			char old_directory[100] = "";
			strcpy(old_directory, filename);
			printf("%s\n", old_directory);

			
			//Cut substring without extension
			int old_length = strlen(old_directory) - 4;
			char oldname[100] = "";
			strncpy(oldname, old_directory, old_length);
			char format[] = "_gray.png";

			strcat(oldname, format);
			printf("%s\n", oldname);
			char new_directory[100] = "/home/dejahvoe/modul2/gambar/";

			//Create new directory
			strcat(new_directory, oldname);
			printf("%s\n", new_directory);
			
//			char coba1[] = "test2.txt";
//			char coba2[] = "test1.txt";
//			char *argv[] = {"mv", old_directory, new_directory, NULL};
//			execv("/bin/mv", argv);
			int success = rename(old_directory, new_directory);
		}
	}

	closedir(directory);

	sleep(1);
	}

	exit(EXIT_SUCCESS);
}
