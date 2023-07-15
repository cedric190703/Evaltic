#include "preprocess.h"

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
                if(isalpha(lastLetter) || isdigit(lastLetter) || lastLetter == ')') {
                    cout << i << endl;
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
            lastLetter = e;
            if(i < size - 1) {
                e = expression[i+1];
                if(e == ' ') {
                    while(i < size && e == ' ') {
                        i++;
                        e = expression[i];
                    }
                    i--;
                    continue;
                    if(isalpha(e) || isdigit(e)) {
                        cerr << "Synthax error detected." << endl;
                        throw runtime_error("Synthax error");
                    }
                }
            }
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
        } else {
            if(e == ';') {
                if(lastLetter == e) {
                    cerr << "Synthax error detected." << endl;
                    throw runtime_error("Synthax error");
                }
                res[idx] = e;
                idx++;
            } else if (e == ',') {
                res[idx] = e;
                idx++;
            }
            else if(e == ' ') {
                continue;
            } else {
                // Error -> Logical error
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