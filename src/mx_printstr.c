#include "header.h"

void mx_printstr(const char *s) 
{
  const char *str = s;
  int length = 0;
  while(*str++)
    length++;
  write(1, s, length);
}

