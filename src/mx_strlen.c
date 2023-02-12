#include "header.h"

int mx_strlen(const char *s) 
{
  int length = 0;
  char i = s[0];
  while (i != '\0') 
  {
    length++;
    i = s[length];
  }
  return length;
}

