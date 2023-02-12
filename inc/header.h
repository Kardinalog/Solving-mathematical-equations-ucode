#ifndef HEADER_H
#define HEADER_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


char *mx_itoa(long long number);
int mx_atoi(const char* str);
bool mx_isdigit(int c);
bool mx_isspace(char c);
char *mx_strnew(const int size);
void mx_printchar(char c);
char *mx_strtrim(const char *str); 
void mx_printint(int n);
void mx_printstr(const char *s);
void mx_printerr(const char *s);
int mx_strlen(const char *s);
double mx_pow(double n, unsigned int pow);
int mx_strcmp (const char *s1, const char *s2);


//тут прототипы функций....(с ними были ошибки, поэтому на всякий случай оставляю пустыми)
void check_args(char* argv[], char* operand1, char* sign, char* operand2, char* result,
    int operand1_length, int sign_length, int operand2_length, int result_length);
void print_decode(char* operand1, char* sign, char* operand2, char* result,
    int operand1_length, int operand2_length, int result_length);


#endif
