#include "header.h"

void print_decode(char* operand1, char* sign, char* operand2, char* result,
    int operand1_length, int operand2_length, int result_length) {
    if (*sign == '?') {
        print_decode(operand1, "+", operand2, result,
            operand1_length, operand2_length, result_length);
        print_decode(operand1, "-", operand2, result,
            operand1_length, operand2_length, result_length);
        print_decode(operand1, "*", operand2, result,
            operand1_length, operand2_length, result_length);
        print_decode(operand1, "/", operand2, result,
            operand1_length, operand2_length, result_length);
        return;
    }
    bool is_operand1_below_zero = false;
    if (operand1[0] == '-') {
        is_operand1_below_zero = true;
        operand1++;
        operand1_length--;
    }
    bool is_operand2_below_zero = false;
    if (operand2[0] == '-') {
        is_operand2_below_zero = true;
        operand2++;
        operand2_length--;
    }
    bool is_result_below_zero = false;
    if (result[0] == '-') {
        is_result_below_zero = true;
        result++;
        result_length--;
    }

    long long first_number = mx_atoi(operand1);
    long long second_number = mx_atoi(operand2);
    long long third_number = mx_atoi(result);

    for (long long i = 0; i < mx_pow(10, operand1_length); i++) {
        if (first_number > 0) {
            i = first_number;
        }
        char* i_str = mx_itoa(i);
        int i_str_length = mx_strlen(i_str);
        bool is_Correct_operand1 = true;

        for (int i_i = 0; i_i < operand1_length - i_str_length; i_i++) {
            if (mx_isdigit(operand1[i_i]) && operand1[i_i] != '0') {
                is_Correct_operand1 = false;
                break;
            }
        }

        for (int i_i = operand1_length - i_str_length, temp = 0; i_i < operand1_length; i_i++, temp++) {
            if (operand1[i_i] != '?' && operand1[i_i] != i_str[temp]) {
                is_Correct_operand1 = false;
                break;
            }
        }

        free(i_str);
        i_str = NULL;
        if (!is_Correct_operand1) {
            continue;
        }

        for (long long j = 0; j < mx_pow(10, operand2_length); j++) {
            if (second_number > 0) {
                j = second_number;
            }
            char* j_str = mx_itoa(j);
            int j_str_length = mx_strlen(j_str);
            bool is_Correct_operand2 = true;

            for (int j_i = 0; j_i < operand2_length - j_str_length; j_i++) {

                if (mx_isdigit(operand2[j_i]) && operand2[j_i] != '0') {
                    is_Correct_operand2 = false;
                    break;
                }
            }

            for (int j_i = operand2_length - j_str_length, temp = 0; j_i < operand2_length; j_i++) {
                temp++;
                if (operand2[j_i] != '?' && operand2[j_i] != j_str[temp]) {
                    is_Correct_operand2 = false;
                    break;
                }
            }

            free(j_str);
            j_str = NULL;
            if (!is_Correct_operand2) {
                continue;
            }

            for (long long k = 0; k < mx_pow(10, result_length); k++) {
                if (third_number > 0) {
                    k = third_number;
                }
                char* k_str = mx_itoa(k);
                int k_str_length = mx_strlen(k_str);
                bool is_Correct_result = true;

                for (int k_i = 0; k_i < result_length - k_str_length; k_i++) {
                    if (mx_isdigit(result[k_i]) && result[k_i] != '0') {
                        is_Correct_result = false;
                        break;
                    }
                }

                for (int k_i = result_length - k_str_length, k_str_i = 0; k_i < result_length; k_i++, k_str_i++) {
                    if (result[k_i] != '?' && result[k_i] != k_str[k_str_i]) {
                        is_Correct_result = false;
                        break;
                    }
                }

                free(k_str);
                k_str = NULL;

                if (!is_Correct_result) {
                    continue;
                }

                //output
                if (is_operand1_below_zero) {
                    i *= -1;
                }
                if (is_operand2_below_zero) {
                    j *= -1;
                }
                if (is_result_below_zero) {
                    k *= -1;
                }

                if (*sign == '+') {
                    if (i + j == k) {
                        mx_printint(i);
                        mx_printstr(" + ");
                        mx_printint(j);
                        mx_printstr(" = ");
                        mx_printint(k);
                        mx_printchar('\n');
                    }
                }
                else if (*sign == '-') {
                    if (i - j == k) {
                        mx_printint(i);
                        mx_printstr(" - ");
                        mx_printint(j);
                        mx_printstr(" = ");
                        mx_printint(k);
                        mx_printchar('\n');
                    }
                }
                else if (*sign == '*') {
                    if (i * j == k) {
                        mx_printint(i);
                        mx_printstr(" * ");
                        mx_printint(j);
                        mx_printstr(" = ");
                        mx_printint(k);
                        mx_printchar('\n');
                    }
                }
                else if (*sign == '/') {
                    if (j != 0 && i / j == k) {
                        mx_printint(i);
                        mx_printstr(" / ");
                        mx_printint(j);
                        mx_printstr(" = ");
                        mx_printint(k);
                        mx_printchar('\n');
                    }
                }

                if (is_operand1_below_zero) {
                    i *= -1;
                }
                if (is_operand2_below_zero) {
                    j *= -1;
                }
                if (is_result_below_zero) {
                    k *= -1;
                }
                if (third_number > 0) {
                    break;
                }
            }
            if (second_number > 0) {
                break;
            }
        }
        if (first_number > 0) {
            break;
        }
    }

    if (is_operand1_below_zero) {
        operand1--;
    }
    if (is_operand2_below_zero) {
        operand2--;
    }
    if (is_result_below_zero) {
        result--;
    }

}

