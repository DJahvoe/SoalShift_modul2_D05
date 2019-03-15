#include <sys/types.h>
#include <sys/stat.h>
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <cstring>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <syslog.h>
#include <time.h>

using namespace std;

int main() {
    pid_t pid, sid;
    pid = fork();\
    if (pid < 0) exit(EXIT_FAILURE);
    if (pid > 0) exit(EXIT_SUCCESS);
    umask(0);
    sid = setsid();
    if (sid < 0) exit(EXIT_FAILURE);
    if ((chdir("/home/yusuf/Documents/makanan/")) < 0) exit(EXIT_FAILURE);
    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);

    string pathEnak="makan_enak.txt";
    int i=1;
    while(true)
    {
        struct stat statEnak;
        stat(pathEnak.c_str(), &statEnak);
        time_t now = time(NULL);
        time_t timefile = statEnak.st_atime;

        if (difftime(now,timefile)<=30) {
            string pathSehat="makan_sehat";
            pathSehat += to_string(i) + ".txt";
            FILE *sehat=fopen((char*)pathSehat.c_str(),"w");
            fclose(sehat);
            i++;
        }
        sleep(5);
    }
    exit(EXIT_SUCCESS);
}
