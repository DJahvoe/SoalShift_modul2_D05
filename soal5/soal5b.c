#include <stdio.h>
#include <unistd.h>

int main () {

  char *argv[3] = {"pkill", "soal5a", NULL};
  execv("/usr/bin/pkill", argv);
  return 0;
}
