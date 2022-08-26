#include <stdio.h>
#include <time.h>
#include "myadd.h"

int add(int a, int b)
{
  char buf[32];
  getDateAndTime(buf);
  printf("[%s] calling c add with: a=%d, b=%d \n", buf, a, b);

  return a + b;
}

void getDateAndTime(char *buf)
{
  time_t now = time(NULL);
  struct tm l = *localtime(&now);
  sprintf(buf, "%02d-%02d-%02d %02d:%02d:%02d", l.tm_year + 1900, l.tm_mon + 1, l.tm_mday, l.tm_hour, l.tm_min, l.tm_sec);
}