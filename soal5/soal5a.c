#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <syslog.h>
#include <string.h>

//Time Library
#include <time.h>

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

  if ((chdir("/home/dejahvoe/log")) < 0) {
    exit(EXIT_FAILURE);
  }

  close(STDIN_FILENO);
  close(STDOUT_FILENO);
  close(STDERR_FILENO);

  while(1) {
	time_t rawtime = time(NULL);

	char strtime[200];
	strftime(strtime, 200, "%d:%m:%Y-%H:%M", localtime(&rawtime));
//	printf("%s", strtime);

	mkdir(strtime, S_IRWXU | S_IRWXG | S_IRWXO);
	int i;
	for(i = 1; i <= 30; i++) {
		sleep(60);

		char combined[200] = "";
		strcat(combined, strtime);

		char filename[20];
		sprintf(filename, "/log%d.log", i);

		strcat(combined, filename);

		FILE *source, *target;
		char sourcefile[200] = "/var/log/syslog";
		char targetfile[200];
		strcpy(targetfile, combined);

//		printf("%s\n", sourcefile);
//		printf("%s\n", targetfile);

		source = fopen(sourcefile, "r");
		target = fopen(targetfile, "w");

		char ch;
		while((ch = fgetc(source)) != EOF){
			fputc(ch, target);
		}

		fclose(source);
		fclose(target);
	}
  }
  
  exit(EXIT_SUCCESS);
}
