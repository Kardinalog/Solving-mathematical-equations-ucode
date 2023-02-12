#include "header.h"

int mx_atoi(const char* str) 
{
    int num = 0;
    int chr = 0;
    if (str[0] == '-') 
    {
      chr = 1;
      str++;
    }
    while(*str >= '0' && *str <= '9') 
    {
      num *= 10;
      if (mx_isspace(*str) || !mx_isdigit(*str)) 
        return 0;
      num += *str++;
      if ((mx_isspace(*str) || !mx_isdigit(*str)) && *str) 
        return 0;
      num -= '0';
    }
    if (*str != '\0') 
      return 0;
    if(chr == 1)
      num *= -1;
    return num;
}

