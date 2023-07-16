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

char** preprocessExpression(char* expression, int* nbStr) {
    size_t size = getSize(expression);
    char lastLetter = '$';
    char** res = (char**)malloc((*nbStr+2)*sizeof(char*));
    size_t idx = 0;
    res[*nbStr] = (char*)malloc((idx+2)*sizeof(char));
    size_t i;
    char e;
    int lastSemiColon = 1;
    for(i = 0; i < size; i++) {
        e = expression[i];
        if(isOperator(e)) {
            // Operator
            if(e != '+' && e != '-') {
                res[*nbStr] = (char*)realloc(res[*nbStr],(idx+3)*sizeof(char));
                res[*nbStr][idx] = (e == '.') ? '*' : e;
                idx++;
            } else {
                // Case series of operations + and -
                int sign = getSign(expression, &i, size);
                if(isalpha(lastLetter) || isdigit(lastLetter) || lastLetter == ')') {
                    res[*nbStr] = (char*)realloc(res[*nbStr],(idx+3)*sizeof(char));
                    res[*nbStr][idx] = (sign % 2 == 0) ? '+' : '-';
                    idx++;
                } else {
                    if(sign % 2 != 0) {
                        res[*nbStr] = (char*)realloc(res[*nbStr],(idx+3)*sizeof(char));
                        res[*nbStr][idx] = '-';
                        idx++;
                    }
                }
            }
        } else if(isalpha(e)) {
            res[*nbStr] = (char*)realloc(res[*nbStr],(idx+3)*sizeof(char));
            res[*nbStr][idx] = tolower(e);
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
                    if(isalpha(e) || isdigit(e)) {
                        cerr << "Synthax error detected." << endl;
                        throw runtime_error("Synthax error");
                    }
                }
            }
            continue;
        } else if(isdigit(e)) {
            res[*nbStr] = (char*)realloc(res[*nbStr],(idx+3)*sizeof(char));
            res[*nbStr][idx] = e;
            idx++;
        } else if(islogicalOperator(e)) {
            // Check before
            if(i != 0) {
                if(isOperator(expression[i-1])) {
                    cerr << "Synthax error detected." << endl;
                    throw runtime_error("Synthax error");
                } else {
                    res[*nbStr] = (char*)realloc(res[*nbStr],(idx+3)*sizeof(char));
                    res[*nbStr][idx] = e;
                    idx++;
                }
            }
        } else {
            if(e == ';') {
                if(lastLetter == e) {
                    cerr << "Synthax error detected." << endl;
                    throw runtime_error("Synthax error");
                }
                if(i < size) {
                    res[*nbStr][idx] = '\0';
                    ++*nbStr;
                    res = (char**)realloc(res,(*nbStr+2)*sizeof(char*));
                    idx = 0;
                    res[*nbStr] = (char*)malloc((idx+2)*sizeof(char));
                }
            } else if (e == ',') {
                res[*nbStr] = (char*)realloc(res[*nbStr],(idx+3)*sizeof(char));
                res[*nbStr][idx] = e;
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
    res[*nbStr][idx] = 0;
    ++*nbStr;
    return res;
}