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

  if (pid < 0) {
    exit(EXIT_FAILURE);
  }

  if (pid > 0) {
    exit(EXIT_SUCCESS);
  }

  umask(0);

  sid = setsid();

  if (sid < 0) {
    exit(EXIT_FAILURE);
  }

  if ((chdir("/home/dejahvoe/Sisop/FolderShift2/soal2")) < 0) {
    exit(EXIT_FAILURE);
  }

  close(STDIN_FILENO);
  close(STDOUT_FILENO);
  close(STDERR_FILENO);

  while(1) {
	struct stat inf;
	if(stat("./hatiku/elen.ku", &inf) != 0) {
		perror("stat() error");
	}
	else {
		int owner_id = inf.st_uid;
		int group_id = inf.st_gid;
		//printf("%d %d\n", owner_id, group_id);
		
		//dapat ID id -u www-data
		if(owner_id == 33 && group_id == 33) {
			int changemod = chmod("./hatiku/elen.ku", 777);
			int removefile = remove("./hatiku/elen.ku");
		}
	}
    sleep(3);
  }
  
  exit(EXIT_SUCCESS);
}
