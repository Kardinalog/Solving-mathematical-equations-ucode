#include "header.h"

void check_args(char* argv[], char* operand1, char* sign, char* operand2, char* result,
    int operand1_length, int sign_length, int operand2_length, int result_length) {

    if (operand1_length <= 0) {
        mx_printerr("Invalid operand1: ");
        mx_printerr(argv[1]);
        mx_printerr("\n");
        exit(-1);
    }
    if (sign_length != 1) {
        mx_printerr("Invalid sign: ");
        mx_printerr(argv[2]);
        mx_printerr("\n");
        exit(-1);
    }
    if (operand2_length <= 0) {
        mx_printerr("Invalid operand2: ");
        mx_printerr(argv[3]);
        mx_printerr("\n");
        exit(-1);
    }
    if (result_length <= 0) {
        mx_printerr("Invalid result: ");
        mx_printerr(argv[4]);
        mx_printerr("\n");
        exit(-1);
    }

    for (int i = 0; i < operand1_length; i++) {
        if (i == 0 && operand1[i] == '-') {
            continue;
        }
        if (operand1[i] != '?' && !mx_isdigit(operand1[i])) {
            mx_printerr("Invalid operand: ");
            mx_printerr(argv[1]);
            mx_printerr("\n");
            exit(-1);
        }
    }

    if (*sign != '?' && *sign != '+' && *sign != '-' && *sign != '*' && *sign != '/') {
        mx_printerr("Invalid sign: ");
        mx_printerr(argv[2]);
        mx_printerr("\n");
        exit(-1);
    }

    for (int i = 0; i < operand2_length; i++) {
        if (i == 0 && operand2[i] == '-') {
            continue;
        }
        if (operand2[i] != '?' && !mx_isdigit(operand2[i])) {
            mx_printerr("Invalid operand: ");
            mx_printerr(argv[3]);
            mx_printerr("\n");
            exit(-1);
        }
    }

    for (int i = 0; i < result_length; i++) {
        if (i == 0 && result[i] == '-') {
            continue;
        }
        if (result[i] != '?' && !mx_isdigit(result[i])) {
            mx_printerr("Invalid operand: ");
            mx_printerr(argv[4]);
            mx_printerr("\n");
            exit(-1);
        }
    }

}

