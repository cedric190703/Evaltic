#include "preprocess.h"

size_t getSize(char* expression) {
    size_t size = 0;
    while(expression[size]) {
        size++;
    }
    return size;
}

int isOperator(char e) {
    return (e == '+' || e == '-' || e == '*' || e == '/' || e == '%' || e == '(' || e == ')') ? 1 : 0;
}

int getSign(char* expression, size_t* idx, size_t size) {
    int cpt = 0;
    while(*idx < size && (expression[*idx] == '+' || expression[*idx] == '-' || expression[*idx] == ' ')) {
        if(expression[*idx] == '-') {
            cpt++;
        }
        *idx = *idx+1;
    }
    *idx = *idx-1;
    return cpt;
}

int islogicalOperator(char e) {
    return (e == '=' || e == '<' || e == '>') ? 1 : 0;
}

char* preprocessExpression(char* expression) {
    size_t size = getSize(expression);
    char lastLetter = '$';
    char* res = (char*)malloc((size+2)*sizeof(char));
    size_t i;
    size_t idx = 0;
    char  e;
    int lastSemiColon = 1;
    for(i = 0; i < size; i++) {
        e = expression[i];
        if(isOperator(e)) {
            // Operator
            if(e != '+' && e != '-') {
                res[idx] = (e == '.') ? '*' : e;
                idx++;
            } else {
                // Case series of operations + and -
                int sign = getSign(expression, &i, size);
                if(isalpha(lastLetter) || isdigit(lastLetter)) {
                    res[idx] = (sign % 2 == 0) ? '+' : '-';
                    idx++;
                } else {
                    if(sign % 2 != 0) {
                        res[idx] = '-';
                        idx++;
                    }
                }
            }
        } else if(isalpha(e)) {
            res[idx] = tolower(e);
            idx++;
        } else if(isdigit(e)) {
            res[idx] = e;
            idx++;
        } else if(islogicalOperator(e)) {
            // Check before
            if(i != 0) {
                if(isOperator(expression[i-1])) {
                    cerr << "Synthax error detected." << endl;
                    throw runtime_error("Synthax error");
                } else {
                    res[idx] = e;
                    idx++;
                }
            }
            // Check after
            if(i < size-1) {
                if(expression[i+1] == '=' || expression[i+1] == '!') {
                    res[idx] = expression[i+1];
                    idx++;
                }
            }
        } else {
            if(e == ';') {
                res[idx] = e;
            } else if(e == ' ') {
                continue;
            } else {
                // Error -> Logical error
                cout << e << endl;
                cerr << "Logical error detected." << endl;
                throw runtime_error("Logical error");
            }
        }
        lastLetter = e;
    }
    if(res[idx-1] != ';') {
        res[idx] = ';';
        idx++;
    }
    res[idx] = 0;
    return res;
}