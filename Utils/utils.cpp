#include "../Utils/utils.h"

int isOperatorConversion(char e) {
    return (e == '+' || e == '-' || e == '*' || e == '/' || e == '%' || e == '^') ? 1 : 0;
}

int isOperator(char e) {
    return (e == '+' || e == '-' || e == '*' || e == '/' || e == '%' || e == '(' || e == ')' || e == '^') ? 1 : 0;
}

int islogicalOpConversion(char e) {
    return (e == '<' || e == '>') ? 1 : 0;
}

int islogicalOperator(char e) {
    return (e == '=' || e == '<' || e == '>') ? 1 : 0;
}

int isTernaryOp(char e) {
    return (e == '?' || e == ':') ? 1 : 0;
}

size_t getSize(char* expression) {
    size_t size = 0;
    while(expression[size]) {
        size++;
    }
    return size;
}