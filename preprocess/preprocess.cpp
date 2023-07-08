#include "preprocess.h"

size_t getSize(char* expression) {
    size_t size = 0;
    while(expression[size]) {
        size++;
    }
    return size;
}

int isOperator(char e) {
    if(e == '+' || e == '-' || e == '*' || e == '/' || e == '%') {
        return 1; 
    }
    return 0;
}

int getSign(char* expression) {
    // TODO
}

char* preprocessExpression(char* expression) {
    size_t size = getSize(expression);
    char lastLetter = NULL;
    char* res = (char*)malloc(size*sizeof(char));
    for(int i = 0; i < size; i++) {
        char e = expression[i];
        if(isOperator(e)) {
            // Operator
        } else if(isdigit(e)) {
            // Digit
        } else if(isalpha(e)) {
            // Letter
        } else {
            // Error -> Logical error
        }
        lastLetter = e;
    }
}